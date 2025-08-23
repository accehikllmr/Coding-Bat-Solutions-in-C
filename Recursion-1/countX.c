/* Given a string, compute recursively (no loops) the number of lowercase 'x' chars in the string.
 *
 * countX("xxhixx") → 4
 * countX("xhixhix") → 3
 * countX("hi") → 0
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 50

unsigned long countX(char *);

int main() {

	char *input = (char *)calloc(SIZE, sizeof(char));

	printf("String: ");
	fgets(input, SIZE, stdin);
	*(input + strlen(input) - 1) = '\0';

	printf("Count of 'x' characters in %s is: %lu\n", input, countX(input));

	free(input);

	return 0;
}

unsigned long countX(char *str) {

	if (*str == '\0') return 0;
	else return ((*str == 'x') ? 1 : 0) + countX(str + 1);
}
