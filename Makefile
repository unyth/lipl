CFLAGS := $(CFLAGS) -std=c99 -Wall

strings: strings.c
	cc $(CFLAGS) strings.c mpc.c -ledit -lm -o strings

clean:
	rm strings
