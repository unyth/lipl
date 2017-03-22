// #include <stdio.h>
// #include <stdlib.h>

#include <editline/readline.h>
#include <editline/history.h>

#include "mpc.h"

// enum { LERR_DIV_ZERO, LERR_BAD_OP, LERR_BAD_NUM };

enum { LVAL_NUM, LVAL_ERR, LVAL_SYM, LVAL_SEXPR };

// new lval type
typedef struct lval {
	int type;
	long num;
	char* err;
	char* sym;
	int count;
	struct lval** cell;
} lval;

// lval constructor for numbers
lval* lval_num(long x) {
	lval* v = malloc(sizeof(lval));
	v->type = LVAL_NUM;
	v->num = x;
	return v;
}

//lval constructor for errors
lval* lval_err(char* error_message) {
	lval* v = malloc(sizeof(lval));
	v->type = LVAL_ERR;
	v->err = malloc(strlen(error_message) + 1);
	strcpy(v->err, m);
	return v;
}

//lval constructor for symbol

//lval constructor for sexpr


lval lval_num(long x) {
	lval v;
	v.type = LVAL_NUM;
	v.num = x;
	return v;
}

lval lval_err(int x) {
	lval v;
	v.type = LVAL_ERR;
	v.err = x;
	return v;
}

void lval_print(lval v) {
	switch (v.type) {
		case LVAL_NUM: printf("%li", v.num); break;
		case LVAL_ERR: 
			       if (v.err == LERR_DIV_ZERO)
				       printf("Error: Division by Zero");
			       if (v.err == LERR_BAD_OP)
				       printf("Error: Invalid Operator!");
			       if (v.err == LERR_BAD_NUM)
				       printf("Error: Invalid Number!");
			       break;
	}
}

void lval_println(lval v) { lval_print(v); printf("\n"); }

lval eval_op(lval x, char* op, lval y) {

	if (x.type == LVAL_ERR) return x;
	if (y.type == LVAL_ERR) return y;

	if (strcmp(op, "+") == 0) {return lval_num(x.num + y.num);}
	if (strcmp(op, "-") == 0) {return lval_num(x.num - y.num);}
	if (strcmp(op, "*") == 0) {return lval_num(x.num * y.num);}
	if (strcmp(op, "/") == 0) {
		return y.num == 0 ? lval_err(LERR_DIV_ZERO) : lval_num(x.num / y.num);}

	return lval_err(LERR_BAD_OP);
}

lval eval(mpc_ast_t* t) {

	if (strstr(t->tag, "number")) {
		errno = 0;
		long x = strtol(t->contents, NULL, 10);
		return errno != ERANGE ? lval_num(x) : lval_err(LERR_BAD_NUM);
	}

	char* op = t->children[1]->contents;

	lval x = eval(t->children[2]);

	int i = 3;

	while(strstr(t->children[i]->tag, "expr")) {
		x = eval_op(x, op, eval(t->children[i]));
		i++;
	}

	return x;
}

int main (int argc, char **argv) {

	/* MPC parsers */
	mpc_parser_t* Number = mpc_new("number");
	mpc_parser_t* Operator = mpc_new("operator");
	mpc_parser_t* Sexpr = mpc_new("sexpr");
	mpc_parser_t* Expr = mpc_new("expr");
	mpc_parser_t* Lipl = mpc_new("lipl");
	
	/* MPC Grammar */
	mpca_lang(MPCA_LANG_DEFAULT,
	  " number	: /-?[0-9]+/ ;				\
	    operator	: '+'|'-'|'*'|'/' ;			\
	    sexpr	: '(' <expr>* ')' ;			\
	    expr	: <number> | <symbol> | <sexpr> ;	\
	    lipl	: /^/ <expr>* /$/ ;" ,
	  Number, Symbol, Sexpr, Expr, Lipl);

	puts("lipl version 0.0.0.0.2");
	puts("Press ctrl + c to exit");
	puts("");

	while(1) {
		char* input = readline("lipl>>> ");
		add_history(input);
		
		mpc_result_t r;
		if (mpc_parse("<stdin>", input, Lipl, &r)) { lval result = eval(r.output);
			lval_println(result);
			mpc_ast_delete(r.output);
		} else {
			mpc_err_print(r.error);
			mpc_err_delete(r.error);
		}

		free(input);
	}

	/* Clean Up */
	mpc_cleanup(5, Number, Operator, Sexpr, Expr, Lipl);
}
