CFLAGS := $(CFLAGS) -std=c99 -Wall

prompt: prompt.c
	gcc prompt.c $(CFLAGS) -ledit -o prompt

clean:
	rm prompt
