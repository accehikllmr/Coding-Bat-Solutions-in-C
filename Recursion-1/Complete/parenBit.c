/* Given a string that contains a single pair of parenthesis, compute recursively a new string made of only of 
 * the parenthesis and their contents, so "xyz(abc)123" yields "(abc)".
 *
 * parenBit("xyz(abc)123") → "(abc)"
 * parenBit("x(hello)") → "(hello)"
 * parenBit("(xy)1") → "(xy)"
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SIZE 50

void parenBit(char *, char *, int);

int main() {

	char *input = (char *)calloc(SIZE, sizeof(char));
	printf("String: ");
	fgets(input, SIZE, stdin);
	*(input + strlen(input) - 1) = 0;

	printf("%s reduced to the contents within and including its parentheses is ", input);
	parenBit(input, input, 0);
	printf("%s\n", input);

	free(input);

	return 0;
}

void parenBit(char *read, char *write, int flag) {

	// continue until reaching null character after original input string, to overwrite all leftover elements
	if (*write != 0) {

		// flag to track whether before, within or after parentheses
		flag = (*read == '(') ? 1 : flag;

		// within parentheses
		if (flag == 1) {
			// overwrite original character
			*write = *read;
			// change flag value if encountering right parenthesis
			flag = (*read == ')') ? -1 : flag;
			// increment both read and write, since element was overwritten
			parenBit(read + 1, write + 1, flag);
		// after parentheses
		} else if (flag == - 1) {
			// overwrite remaining elements with null characters
			*write = 0;
			// stop incrementing read pointer
			parenBit(read, write + 1, flag);
		// before parentheses, keep incrementing read pointer until reaching left parenthesis
		} else parenBit(read + 1, write, flag);
	
	}
}
