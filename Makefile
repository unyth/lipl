CFLAGS := $(CFLAGS) -std=c99 -Wall

comments: comments.c
	cc $(CFLAGS) comments.c mpc.c -ledit -lm -o comments

clean:
	rm comments
