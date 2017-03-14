#include <stdio.h>
#include <stdlib.h>

#include <editline/readline.h>
#include <editline/history.h>

#include "mpc.h"

int main (int argc, char **argv) {

	/* MPC parsers */
	mpc_parser_t* Number = mpc_new("number");
	mpc_parser_t* Operator = mpc_new("operator");
	mpc_parser_t* Expr = mpc_new("expr");
	mpc_parser_t* Lipl = mpc_new("lipl");

	/* MPC Grammar */
	mpca_lang(MPCA_LANG_DEFAULT,
	  " number	: /-?[0-9]+/ ;				\
	    operator: '+'|'-'|'*'|'/' ;				\
	    expr	: <number> | '(' <operator> <expr>+ ')';\
	    lipl	: /^/ <operator> <expr>+ /$/ ;" ,
	Number, Operator, Expr, Lipl);

	puts("lipl version 0.0.0.0.1");
	puts("Press ctrl + c to exit");
	puts("");

	while(1) {
		char* input = readline("lipl>>> ");
		add_history(input);
		
		mpc_result_t r;
		if (mpc_parse("<stdin>", input, Lipl, &r)) {
			mpc_ast_print(r.output);
			mpc_ast_delete(r.output);
		} else {
			mpc_err_print(r.error);
			mpc_err_delete(r.error);
		}

		free(input);
	}

	/* Clean Up */
	mpc_cleanup(4, Number, Operator, Expr, Lipl);
}