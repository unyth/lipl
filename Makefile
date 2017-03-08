CFLAGS := $(CFLAGS) -std99 -Wall

prompt: prompt.c
	gcc prompt.c -o prompt

clean:
	rm prompt
