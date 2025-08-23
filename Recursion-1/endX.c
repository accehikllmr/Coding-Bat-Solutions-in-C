/* Given a string, compute recursively a new string where all the lowercase 'x' chars have been moved to the end 
 * of the string.
 *
 * endX("xxre") → "rexx"
 * endX("xxhixx") → "hixxxx"
 * endX("xhixhix") → "hihixxx"
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SIZE 50

void endX(char *);

int main() {

	char *input = (char *)calloc(SIZE, sizeof(char));

	printf("String: ");
	fgets(input, SIZE, stdin);
	*(input + strlen(input) - 1) = '\0';

	printf("%s with all 'x' characters at the end is ", input);
	endX(input);
	printf("%s\n", input);

	free(input);

	return 0;
}

void endX(char *str) {

	// stop sorting characters once last non-null character is reached
	if (*(str + 1) != '\0') {
		// recursive call, so that sorting starts with rightmost characters first
		endX(str + 1);
		// rearrange order of characters only if 'x' is first and also not second
		if (*str == 'x' && *(str + 1) != 'x') {
			// standard swapping algorithm
			char temp = *str;
			*str = *(str + 1);
			*(str + 1) =  temp;
			// recursive call to keep shifting 'x' to the right, all the way to the end of the string
			endX(str + 1);
		}
	}
}
