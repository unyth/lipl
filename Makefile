CFLAGS := $(CFLAGS) -std=c99 -Wall

q_expression: q_expression.c
	cc $(CFLAGS) q_expression.c mpc.c -ledit -lm -o q_expression

clean:
	rm q_expression
