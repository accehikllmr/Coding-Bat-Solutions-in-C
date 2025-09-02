/* Given a string, compute recursively a new string where all the adjacent chars are now separated by a "*".
 *
 * allStar("hello") → "h*e*l*l*o"
 * allStar("abc") → "a*b*c"
 * allStar("ab") → "a*b"
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SIZE 50

void allStar(char *, char *);

int main() {

	char *input = (char *)calloc(SIZE, sizeof(char));
	
	printf("String: ");
	fgets(input, SIZE, stdin);
	*(input + strlen(input) - 1) = '\0';

	char *inputStars = (char *)calloc(2 * strlen(input), sizeof(char));

	allStar(input, inputStars);

	printf("%s with stars in between is %s\n", input, inputStars);

	free(input);
	free(inputStars);

	return 0;
}

void allStar(char *str, char *starStr) {

	if (*(str + 1) != '\0') {

		*starStr = *str;
		*(starStr + 1) = '*';
		allStar(str + 1, starStr + 2);
	
	} else if (*str != '\0') {
		
		*starStr = *str;	
	}
}
