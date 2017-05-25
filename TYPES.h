#define TYPES_H

//Forward Declarations
//TODO: Figure out how this works, and why it can't be simplified
struct lval;
struct env;
typedef struct lenv lenv;
typedef struct lval lval;

//TODO: Figure out how functional pointer works
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
	lval** cell;
};

// env type
struct lenv {
	lenv* parent;
	int count;
	char** syms;
	lval** vals;
};