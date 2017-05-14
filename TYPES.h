#define TYPES_H

struct lval;
struct env;
typedef struct lenv lenv;
typedef struct lval lval;
typedef lval*(*lbuiltin)(lenv*, lval*);

// lval type
struct lval{
	int type;

	/* Basic */
	long num;
	char* err;
	char* sym;
	
	/* Function Related */
	lbuiltin builtin;
	lenv* env;
	lval* formals;
	lval* body;

	/* Expression */
	int count;
	struct lval** cell;
};

// env type
struct lenv {
	int count;
	char** syms;
	lval** vals;
};