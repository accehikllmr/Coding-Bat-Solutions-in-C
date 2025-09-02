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

void allStar(int, int, char *);

int main() {

	char *input = (char *)calloc(SIZE, sizeof(char));
	
	printf("String: ");
	fgets(input, SIZE, stdin);
	*(input + strlen(input) - 1) = '\0';

	printf("%s starred is ", input);
	// passing flag for tracking letter or *, last index of original input, ptr to end of new string
	allStar(1, strlen(input) - 1, input + 2 * (strlen(input) - 1));
	printf("%s\n", input);

	free(input);

	return 0;
}

void allStar(int flag, int diff, char *end) {

	// difference between ptr address and address of character from original string, 0 when at leftmost char
	if (diff != -1) {

		// value of 1 for overwriting with character from original string
		if (flag == 1) {
			// overwriting using character from original string, diff find correct character
			*end = *(end - diff);
			// flip flag since next overwrite is '*', decrement difference, since leftmost character 
			// has diff of 0 between original string and new string, decrement ptr since moving left
			allStar(0, diff - 1, end - 1);
		
		} else {
			// flag is 0, so overwriting with '*' instead of original char from string
			*end = '*';
			// diff unchanged, since added '*' does not correspond to character from original string
			allStar(1, diff, end - 1);
		}
	}
}
