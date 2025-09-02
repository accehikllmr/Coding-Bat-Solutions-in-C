/* Given a string, compute recursively (no loops) the number of times lowercase "hi" appears in the string.
 *
 * countHi("xxhixx") → 1
 * countHi("xhixhix") → 2
 * countHi("hi") → 1
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SIZE 50

unsigned long countHi(char *);

int main() {
	// initializing memory allocation to random arbitrary size, since input size unknown before runtime
	char *input = (char *)calloc(SIZE, sizeof(char));

	printf("String: ");
	fgets(input, SIZE, stdin);
	*(input + strlen(input) - 1) = '\0';

	printf("\"hi\" appears %lu times in the string %s\n", countHi(input), input);

	free(input);

	return 0;
}

unsigned long countHi(char *str) {
	// once null character is next, no more matches possible so end recursion
	if (*(str + 1) == '\0') return 0;
	// otherwise, add 1 if both characters match string "hi", and run recursion on substring
	else return ((*str == 'h' && *(str + 1) == 'i') ? 1 : 0) + countHi(str + 1);
}
