#include <stdio.h>

static char input[2048];

int main (int argc, char **argv) {
	puts("lipl version 0.0.0.0.1");
	puts("Press ctrl + c to exit");
	puts("");

	while(1) {
		fputs("lipl>>> ", stdout);
		fgets(input, 2048, stdin);
		fprintf(stdout, "No, you are a %s", input);
	}
}
