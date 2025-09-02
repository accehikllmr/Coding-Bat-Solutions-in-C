/* Given a string, compute recursively (no loops) a new string where all the lowercase 'x' chars have been changed 
 * to 'y' chars.
 *
 * changeXY("codex") → "codey"
 * changeXY("xxhixx") → "yyhiyy"
 * changeXY("xhixhix") → "yhiyhiy"
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 50

void changeXY(char *);

int main() {

	char *input = (char *)calloc(SIZE, sizeof(char *));

	printf("String: ");
	fgets(input, SIZE, stdin);
	*(input + strlen(input) - 1) = '\0';

	printf("%s with 'y' characters replacing 'x' characters is ", input);
	changeXY(input);
	printf("%s\n", input);

	free(input);

	return 0;
}

void changeXY(char *str) {

	if (*str != '\0') {

		if (*str == 'x') *str = 'y';
		changeXY(str + 1);
	}
}
