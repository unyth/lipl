CFLAGS := $(CFLAGS) -std=c99 -Wall

functions: functions.c
	cc $(CFLAGS) functions.c mpc.c -ledit -lm -o functions

clean:
	rm functions
