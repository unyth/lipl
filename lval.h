struct lval;
struct env;
typedef struct lenv lenv;
typedef struct lval lval;
typedef lval*(*lbuiltin)(lenv*, lval*);

// lval type
typedef struct lval{
	int type;

	long num;
	char* err;
	char* sym;
	lbuiltin fun;

	int count;
	struct lval** cell;
} lval;

/* Function Prototypes */

//Constructors
lval* lval_num(long x);
lval* lval_err(char* error_message);
lval* lval_sym(char* symbol);
lval* lval_sexpr(void);
lval* lval_qexpr(void);
lval* lval_fun(lbuiltin func);

//Destructor
void lval_del(lval* v);

//Utilities
lval* lval_copy(lval* v);
lval* lval_eval(lval* v);
lval* lval_read_num(mpc_ast_t* t);
lval* lval_add(lval* v, lval* x);
lval* lval_read(mpc_ast_t* t);
void lval_print(lval* v);
void lval_expr_print(lval* v, char open, char close);
void lval_println(lval* v);
lval* lval_pop(lval* v, int i);
lval* lval_take(lval* v, int i);
