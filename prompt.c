#include <stdio.h>
#include <stdlib.h>

#include <editline/readline.h>
#include <editline/history.h>

int main (int argc, char **argv) {
	puts("lipl version 0.0.0.0.1");
	puts("Press ctrl + c to exit");
	puts("");

	while(1) {
		char* input = readline("lipl>>> ");
		add_history(input);
		fprintf(stdout, "No, you are a %s\n", input);
		free(input);
	}
}
