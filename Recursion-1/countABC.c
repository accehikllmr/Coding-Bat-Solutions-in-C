/* Count recursively the total number of "abc" and "aba" substrings that appear in the given string.
 *
 * countAbc("abc") → 1
 * countAbc("abcxxabc") → 2
 * countAbc("abaxxaba") → 2
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 50

unsigned long countAbc(char *);

int main() {

	char *input = (char *)calloc(SIZE, sizeof(char));

	printf("String: ");
	fgets(input, SIZE, stdin);
	*(input + strlen(input) - 1) = '\0';

	printf("\"abc\" and \"aba\" substrings appear %lu times inn %s\n", countAbc(input), input);

	free(input);

	return 0;
}

unsigned long countAbc(char *str) {

	// base case where string length is 0, and stops recursion when third character from start of substring is null
	if (*str == '\0' || *(str + 2) == '\0') return 0;
	else {
		// flag for sequence of "abc" or "aba" substring
		int isAbc = *str == 'a' && *(str + 1) == 'b' && (*(str + 2) == 'a' || *(str + 2) == 'c');
		// value of flag is 1 or 0, and add to recursive call
		return isAbc + countAbc(str + 1);
	}
}
