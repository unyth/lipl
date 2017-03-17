CFLAGS := $(CFLAGS) -std=c99 -Wall

error_handling: error_handling.c
	cc $(CFLAGS) error_handling.c mpc.c -ledit -lm -o error_handling

clean:
	rm error_handling
