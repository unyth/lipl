CFLAGS := $(CFLAGS) -std=c99 -Wall

s_expression: s_expression.c
	cc $(CFLAGS) s_expression.c mpc.c -ledit -lm -o s_expression

clean:
	rm s_expression
