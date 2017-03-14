CFLAGS := $(CFLAGS) -std=c99 -Wall

parsing: parsing.c
	cc $(CFLAGS) parsing.c mpc.c -ledit -lm -o parsing

clean:
	rm prompt
