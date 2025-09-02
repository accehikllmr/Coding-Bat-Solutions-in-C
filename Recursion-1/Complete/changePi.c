/* Given a string, compute recursively (no loops) a new string where all appearances of "pi" have been replaced by 
 * "3.14".
 *
 * changePi("xpix") → "x3.14x"
 * changePi("pipi") → "3.143.14"
 * changePi("pip") → "3.14p"
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SIZE 50

void changePi(char *, char *);

int main() {

	char *input = (char *)calloc(SIZE, sizeof(char));
	printf("String: ");
	fgets(input, SIZE, stdin);
	*(input + strlen(input) - 1) = 0;

	// maximum length of new string is twice the size of the original string, since "pi" half length of "3.14"
	char *noPi = (char *)calloc(strlen(input) * 2 + 1, sizeof(char));

	changePi(input, noPi);

	printf("%s with all \"pi\" replaced is %s\n", input, noPi);

	free(input);
	free(noPi);

	return 0;
}

void changePi(char *str, char *newStr) {
	// continue until end of string, cannot end early since single chars must be copied (i.e. not overwrite)
	if (*str != 0) {
		if (*str == 'p' && *(str + 1) == 'i') {
			// add character to new string and increment pointer one memory address
			*newStr++ = '3';
			*newStr++ = '.';
			*newStr++ = '1';
			*newStr++ = '4';
			// increment pointer to original string twice, to avoid reading 'p' and 'i' again
			str++;
			str++;
	
		} else {
			// not "pi" substring, so simply add character to new string
			*newStr++ = *str;
			str++;
		}
		// all incrementing done above, so simply pass updated values to recursive function call
		changePi(str, newStr);
	}
}
