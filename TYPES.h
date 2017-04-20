#define TYPES_H

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

// env type
struct lenv {
	int count;
	char** syms;
	lval** vals;
};
