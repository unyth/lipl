CFLAGS := $(CFLAGS) -std=c99 -Wall

prompt: prompt.c
	gcc prompt.c $(CFLAGS) -o prompt

clean:
	rm prompt
