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

int strCopies(char *, char *, int, int);

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

	char *result = (strCopies(inputStr, inputSub, count, strlen(inputSub))) ? "true" : "false";

	printf("Substring %s appears in the string %s %d or more times: %s\n", inputSub, inputStr, count, result); 
	
	free(inputStr);
	free(inputSub);

	return 0;
}

int strCopies(char *str, char *sub, int count, int subLength) {
	// checking whether string is shorter than substring (not using strlen, since expensive)
	if (*(str + strlen(sub) - 1) != '\0') {
		// identical characters in string and substring
		if (*str == *sub) {
			// incrementing substring first, since need to check if end has been reached
			sub++;
			if (*sub == '\0') {
				// end reached, so substring exists in string	
				count--;
				// reset string and substring to original values, for next recursive call
				str -= subLength - 1;
				sub -= subLength;
			}
		// reset string and substring, but substring end was not reached (i.e. not matching chars)
		} else if (strlen(sub) != subLength) {
			// reset str first, otherwise expression would have to be offset, or modified
			str -= subLength - strlen(sub);
			sub -= subLength - strlen(sub);
		}
		// lazy evaluation, or first recursive call will return incorrect value
		return count <= 0 || strCopies(str + 1, sub, count, subLength);
	}
	// count never went below 0, so this value is returned once str reaches end, and disjuncted with other 0s
	return 0;
}
