/* Given a string, compute recursively the number of times lowercase "hi" appears in the string, however do not 
 * count "hi" that have an 'x' immedately before them.
 *
 * countHi2("ahixhi") → 1
 * countHi2("ahibhi") → 2
 * countHi2("xhixhi") → 0
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SIZE 50

unsigned long countHi2(char *);

int main() {
	
	char *input = (char *)calloc(SIZE, sizeof(char));
	printf("String: ");
	/* for algorithm in function, need character preceding first character in string, hence store string one 
	   memory address higher, size of buffer is decreased by 1 since only 49 memory addresses remaining after
	   increment */
	fgets(input + 1, SIZE - 1, stdin);
	// +1 to pointer to string and -1 to strlen cancel out, +1 in brackets since string is located there
	*(input + strlen(input + 1)) = 0;

	// passing beginning of string to function, otherwise will immediately return 0
	printf("excluding instances preceded by 'x', \"hi\" appears %lu times in %s\n", 
			countHi2(input + 1), input + 1);

	free(input);

	return 0;
}

unsigned long countHi2(char *str) {

	// stop when next character is null, since no comparison possible
	if (*(str + 1) != 0) {
		/* preceding character can always be evaluated, since string stored one memory address higher than
		   beginning of memory allocation */
		if (*(str - 1) != 'x' && *str == 'h' && *(str + 1) == 'i') return 1 + countHi2(str + 1);
		else return 0 + countHi2(str + 1);
	}

	return 0;
}
