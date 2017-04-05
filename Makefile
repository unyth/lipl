CFLAGS := $(CFLAGS) -std=c99 -Wall

variables: variables.c
	cc $(CFLAGS) variables.c mpc.c -ledit -lm -o variables

clean:
	rm variables
