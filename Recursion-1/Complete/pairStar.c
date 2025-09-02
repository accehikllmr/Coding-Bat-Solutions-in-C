/* Given a string, compute recursively a new string where identical chars that are adjacent in the original string 
 * are separated from each other by a "*".
 *
 * pairStar("hello") → "hel*lo"
 * pairStar("xxyy") → "x*xy*y"
 * pairStar("aaaa") → "a*a*a*a"
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SIZE 50

void pairStar(char *, char *);

int main() {

	char *input = (char *)calloc(SIZE, sizeof(char));
	printf("String: ");
	fgets(input, SIZE, stdin);
	*(input + strlen(input) - 1) = 0;

	// maximum size of starred string is double the length of the input string
	char *starred = (char *)calloc(2 * strlen(input), sizeof(char));

	// first character will be identical, since no pairs reached yet
	*starred = *input;

	printf("%s with its pairs starred is ", input);
	// passing memory address for pointer to second character, since first was assigned above
	pairStar(input + 1, starred + 1);
	printf("%s\n", starred);

	free(input);
	free(starred);

	return 0;
}

void pairStar(char * str, char *newStr) {
	
	if (*str != 0) {
		// character read is identical to previously written character
		if (*str == *(newStr - 1)) *newStr++ = '*';
		// otherwise, simply copy character to new string and increment pointers along respective strings
		else *newStr++ = *str++;
		// incrementation done above, so simply pass pointers
		pairStar(str, newStr);
	}
}
