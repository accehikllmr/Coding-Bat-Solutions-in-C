/* We'll say that a "pair" in a string is two instances of a char separated by a char. So "AxA" the A's make a 
 * pair. Pair's can overlap, so "AxAxA" contains 3 pairs -- 2 for A and 1 for x. Recursively compute the number of 
 * pairs in the given string.
 *
 * countPairs("axa") → 1
 * countPairs("axax") → 2
 * countPairs("axbx") → 1
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SIZE 50

int countPairs(char *);

int main() {

	char *input = (char *)calloc(sizeof(char), SIZE);
	printf("String: ");
	fgets(input, SIZE, stdin);
	*(input + strlen(input) - 1) = 0;

	printf("%d pairs appear in %s\n", countPairs(input), input);

	free(input);

	return 0;
}

int countPairs(char *str) {
	// when string is shorter than 3 characters (not including null), trivially there are 0 pairs
	if (*str == 0 || *(str + 1) == 0 || *(str + 2) == 0) return 0;
	// compare first and third characters, and recursively call for all substrings of current string
	else return (*str == *(str + 2)) + countPairs(str + 1);
}
