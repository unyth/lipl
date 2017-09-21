CFLAGS := -std=c11 -Wall

load: load.c
	cc $(CFLAGS) load.c mpc.c -ledit -lm -o load

clean:
	rm load
