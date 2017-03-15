CFLAGS := $(CFLAGS) -std=c99 -Wall

evaluation: evaluation.c
	cc $(CFLAGS) evaluation.c mpc.c -ledit -lm -o evaluation

clean:
	rm evaluation
