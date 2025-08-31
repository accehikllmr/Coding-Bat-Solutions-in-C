/* Given a string, return recursively a "cleaned" string where adjacent chars that are the same have been reduced 
 * to a single char. So "yyzzza" yields "yza".
 *
 * stringClean("yyzzza") → "yza"
 * stringClean("abbbcdd") → "abcd"
 * stringClean("Hello") → "Helo"
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SIZE 50

void stringClean(char *, char *);

int main() {

	char *input = (char *)calloc(SIZE, sizeof(char));
	printf("String: ");
	fgets(input, SIZE, stdin);
	*(input + strlen(input) - 1) = 0;

	printf("%s cleaned is ", input);
	stringClean(input + 1, input + 1);
	printf("%s\n", input);

	free(input);

	return 0;
}

void stringClean(char *read, char *write) {

	// if read ptr has not yet reached end of string
	if (*read != 0) {
		
		// if current character is not the same as the previous one
		if (*read != *(read - 1)) {
			*write = *read;
			// increment both pointers, since wrote to string
			stringClean(read + 1, write + 1);

		} else {
			// no increment for write pointer, since did not write to string
			stringClean(read + 1, write);
		}
	
	// condition triggers only when read ptr has reached end of string, valid since write ptr lags behind
	} else if (*write != 0) {
		
		// overwrite remaining characters in string with null
		*write = 0;
		// incrementing  write ptr until reaching the end of the string
		stringClean(read, write + 1);
	}
}
