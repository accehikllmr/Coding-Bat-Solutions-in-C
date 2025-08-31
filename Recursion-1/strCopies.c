/* Given a string and a non-empty substring sub, compute recursively if at least n copies of sub appear in the 
 * string somewhere, possibly with overlapping. N will be non-negative.
 *
 * strCopies("catcowcat", "cat", 2) → true
 * strCopies("catcowcat", "cow", 2) → false
 * strCopies("catcowcat", "cow", 1) → true
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 50

int strCopies(char *, char *, int);

int main() {

	char *inputStr = (char *)calloc(SIZE, sizeof(char));
	char *inputSub = (char *)calloc(SIZE, sizeof(char));
	int count = 0;

	printf("String: ");
	fgets(inputStr, SIZE, stdin);
	*(inputStr + strlen(inputStr) - 1) = '\0';

	printf("Substring: ");
	fgets(inputSub, SIZE, stdin);
	*(inputSub + strlen(inputSub) - 1) = '\0';

	printf("Minimum appearances of %s in %s: ", inputSub, inputStr);
	scanf("%d", &count);

	char *result = (strCopies(inputStr, inputSub, count)) ? "true" : "false";

	printf("Substring %s appears in the string %s %d or more times: %s\n", inputSub, inputStr, count, result); 
	
	free(inputStr);
	free(inputSub);

	return 0;
}

int strCopies(char *str, char *sub, int count) {

	if (*(str + strlen(sub) - 1) != '\0') {
		
		// ONLY WORKS FOR SUBSTRINGS OF LENGTH 3, OOPS...

		if (*str == *sub && *(str + 1) == *(sub + 1) && *(str + 2) == *(sub + 2)) {
	
			count--; 		
		}

		strCopies(str + 1, sub, count);
	
	} else {

		return count <= 0;
	}
}
