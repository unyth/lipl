CFLAGS := $(CFLAGS) -std=c99 -Wall

conditionals: conditionals.c
	cc $(CFLAGS) conditionals.c mpc.c -ledit -lm -o conditionals

example: example.c
	cc $(CFLAGS) example.c mpc.c -ledit -lm -o example

clean:
	rm conditionals
