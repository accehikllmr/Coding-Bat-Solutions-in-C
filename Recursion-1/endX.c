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

	if (*(str + 1) != '\0') {

		endX(str + 1);

		if (*str == 'x' && *(str + 1) != 'x') {

			char temp = *str;
			*str = *(str + 1);
			*(str + 1) =  temp;
			endX(str + 1);
		}
	}
}
