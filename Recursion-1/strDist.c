/* Given a string and a non-empty substring sub, compute recursively the largest substring which starts and ends 
 * with sub and return its length.
 *
 * strDist("catcowcat", "cat") → 9
 * strDist("catcowcat", "cow") → 3
 * strDist("cccatcowcatxx", "cat") → 9
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 50

unsigned long strDist(char *, char *);

int main() {
	
	char *inputStr = (char *)calloc(SIZE, sizeof(char));
	printf("String: ");
	fgets(inputStr, SIZE, stdin);
	*(inputStr + strlen(inputStr) - 1) = 0;

	char *inputSub = (char *)calloc(SIZE, sizeof(char));
	printf("Substring: ");
	fgets(inputSub, SIZE, stdin);
	*(inputSub + strlen(inputSub) - 1) = 0;

	printf("largest substring which start and ends with %s in %s is of length %lu\n", 
			inputStr, inputSub, strDist(inputStr, inputSub));
			
	return 0;
}

unsigned long strDist(char *str, char *sub) {
	
	if (*str != 0) {

		if (*str == *sub) {

			sub++;

			if (*sub == 0) {

	
			}
		}
	}

}

// not found -> 0
// found once -> strlen(sub)
// found once, traverse, find again, substract ptrs
