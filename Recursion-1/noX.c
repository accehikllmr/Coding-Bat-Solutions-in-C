/* Given a string, compute recursively a new string where all the 'x' chars have been removed.
 *
 * noX("xaxb") → "ab"
 * noX("abc") → "abc"
 * noX("xx") → ""
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// arbitrary size to limit length of input string
#define SIZE 50

// IDIOMATIC APPROACH IN C IS TO HAVE THE CALLER (E.G. MAIN) ALLOCATE MEMORY, SINCE CLEAR MEMORY OWNERSHIP, 
// FLEXIBLE AND SAFE, OTHER APPROACH IS USED WHEN SIZE OF STRING BEING CREATED IS UNKNOWN 
// (E.G. INPUT IS A WHOLE FILE)
void noX(char *, char *);

int main() {

	// dynamic allocation of memory for input string, arbitrarily limited to 50	
	char *input = (char*)calloc(SIZE, sizeof(char));
	char *newStr = input;

	printf("Input string: ");
	fgets(input, SIZE, stdin);
	// if input stores data in read-only memory, then not sure why it's possible to modify element...
	*(input + strlen(input) - 1) = '\0';
	
	// break statement is broken up into two parts, since function is void and does not return string
	printf("%s with all 'x' characters removed is: ", input);
	noX(input, newStr);
	printf("%s\n", newStr);
	
	// freeing memory addresses for dynamically allocated memory, both have same memory address
	free(input);

	return 0;
}

void noX(char *str, char *ptr) {

	// first character in array is 'x', so move to next memory address for str, but not for ptr
	if (*str == 'x') noX(str + 1, ptr);
	// null character will be assigned but no recursive call, otherwise assignment and recursive call
	else {
		*ptr = *str;
		// both str and ptr shift to next memory address, using null to check since more efficient than strlen 
		if (*str != '\0') noX(str + 1, ptr + 1); 
	}
}	
