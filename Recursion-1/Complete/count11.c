/* Given a string, compute recursively (no loops) the number of "11" substrings in the string. The "11" substrings 
 * should not overlap.
 *
 * count11("11abc11") → 2
 * count11("abc11x11x11") → 3
 * count11("111") → 1
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SIZE 50

unsigned long count11(char *);

int main() {

	char *input = (char *)calloc(SIZE, sizeof(char));
	printf("String: ");
	fgets(input, SIZE, stdin);
	*(input + strlen(input) - 1) = 0;

	printf("\"11\" appears %lu times in %s\n", count11(input), input);

	free(input);

	return 0;
}

unsigned long count11(char *str) {

	if (*str != 0) {
		// increment pointer two memory addresses if match is found, since cannot count overlap		
		if (*str == '1' && *(str + 1) == '1') return 1 + count11(str + 2);
		else return 0 + count11(str + 1);
	}

	return 0;
}
