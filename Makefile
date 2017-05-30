CFLAGS := $(CFLAGS) -std=c99 -Wall

functions: functions.c
	cc $(CFLAGS) functions.c mpc.c -ledit -lm -o functions

example: example.c
	cc $(CFLAGS) example.c mpc.c -ledit -lm -o example

clean:
	rm functions
	rm example
