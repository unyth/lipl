#ifndef TYPES_H
#include "TYPES.h"
#endif

#define FUNCS_H

/** Function Prototypes **/

/* Constructors */

//lval constructors
lval* lval_num(long x);
lval* lval_err(char* error_message);
lval* lval_sym(char* symbol);
lval* lval_sexpr(void);
lval* lval_qexpr(void);
lval* lval_fun(lbuiltin func);

//lenv constructor
lenv* lenv_new(void);


/* Destructor */

//lval destructor
void lval_del(lval* v);

//lenv destructor
void lenv_del(lenv* e);


/* Utilities */

//lval utilities
lval* lval_copy(lval* v);
lval* lval_eval(lenv* e, lval* v);
lval* lval_eval_sexpr(lenv* e, lval* v);
lval* lval_read_num(mpc_ast_t* t);
lval* lval_add(lval* v, lval* x);
lval* lval_read(mpc_ast_t* t);
void lval_print(lval* v);
void lval_expr_print(lval* v, char open, char close);
void lval_println(lval* v);
lval* lval_pop(lval* v, int i);
lval* lval_take(lval* v, int i);

//lenv utilities
lval* lenv_get(lenv* e, lval* k);
void lenv_put(lenv* e, lval* k, lval* v);

//builtin utilities
lval* builtin_op(lenv* e, lval* a, char* op);
lval* builtin_add(lenv* e, lval* a);
lval* builtin_sub(lenv* e, lval* a);
lval* builtin_mul(lenv* e, lval* a);
lval* builtin_div(lenv* e, lval* a);
void lenv_add_builtin(lenv* e, char* name, lbuiltin func);
void lenv_add_builtins(lenv* e);
lval* builtin_head(lval* a);
lval* builtin_tail(lval* a);
lval* builtin_list(lval* a);
lval* builtin_eval(lval* a);
lval* lval_join(lval* x, lval* y);
lval* builtin_join(lval* a);
lval* builtin(lval* a, char* func);