/* Given a string and a non-empty substring sub, compute recursively the number of times that sub appears in the 
 * string, without the sub strings overlapping.
 *
 * strCount("catcowcat", "cat") → 2
 * strCount("catcowcat", "cow") → 1
 * strCount("catcowcat", "dog") → 0
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SIZE 50

unsigned long strCount(char *, char *, int);

int main() {

	char *inputStr = (char *)calloc(SIZE, sizeof(char));
	char *inputSub = (char *)calloc(SIZE, sizeof(char));

	printf("String: ");
	fgets(inputStr, SIZE, stdin);
	*(inputStr + strlen(inputStr) - 1) = 0;

	printf("Substring: ");
	fgets(inputSub, SIZE, stdin);
	*(inputSub + strlen(inputSub) - 1) = 0;

	// passing length of substring, since need it to reset it to correct memory address after traversing it
	printf("substring %s appears in %s %lu times without overlap\n", 
			inputSub, inputStr, strCount(inputStr, inputSub, strlen(inputSub)));

	free(inputStr);
	free(inputSub);

	return 0;
}

unsigned long strCount(char *str, char *sub, int subLength) {
	// continue until end of input string, otherwise will not compare all characters in substring
	if (*str != 0) {
		if (*str == *sub) {
			sub++;
			// end of substring reached, so appears 1 time, recursion on next character in input string (not resetting)
			if (*sub == 0) return 1 + strCount(str + 1, sub - subLength, subLength);
			// end not yet reached, so continue traversing input string (substring memory address incremented above)
			else return 0 + strCount(str + 1, sub, subLength);
		// no match and substring pointer not at original memory address, reset ptr and repeat comparison with same char
		} else if (strlen(sub) != subLength) return 0 + strCount(str, sub - subLength + strlen(sub), subLength);
		// no match but substring pointer at original position, continue traversing input string
		else return 0 + strCount(str + 1, sub, subLength);

	} else return 0;

}
