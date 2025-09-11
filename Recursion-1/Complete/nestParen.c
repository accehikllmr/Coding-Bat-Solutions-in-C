/* Given a string, return true if it is a nesting of zero or more pairs of parenthesis, like "(())" or "((()))". 
 * Suggestion: check the first and last chars, and then recur on what's inside them.
 *
 * nestParen("(())") → true
 * nestParen("((()))") → true
 * nestParen("(((x))") → false
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SIZE 50

int nestParen(char *, char *);

int main() {

	char *input = (char *)calloc(SIZE, sizeof(char));
	printf("String: ");
	fgets(input, SIZE, stdin);
	*(input + strlen(input) - 1) = 0;

	char *result = (nestParen(input, input + strlen(input) - 1) == 1) ? "" : "not ";

	printf("%s is %sa nesting of parentheses\n", input, result);

	free(input);

	return 0;	
}

int nestParen(char *head, char *tail) {
	// only even length input strings satisfy nest condition, need absolute value since modulo becomes negative
	if (abs((tail - head) % 2) == 1) {
		// stop checking for matching parentheses once pointers cross one another
		if (head < tail) {
			// increment head pointer and decrement tail pointer, so both towards the middle of inputstring
			if (*head == '(' && *tail == ')') return nestParen(head + 1, tail - 1);
			// if either dereferenced pointer is not the correctly oriented parenthesis, trivially false
			else return 0;
		}
		// all checks passed, so true
		return 1;
	// odd length input strings
	} else return 0;
}
