/* 
 * We have a number of bunnies and each bunny has two big floppy ears. We want to compute the total number of ears across all the bunnies recursively (without loops or multiplication).
 * 
 * bunnyEars(0) → 0
 * bunnyEars(1) → 2
 * bunnyEars(2) → 4
 */

#include<stdio.h>

unsigned long bunnyEars(unsigned long);

int main() {

	// not int, in order to allow for larger quantities of bunnies, 'int' not needed since implied
	unsigned long bunnies = 0;
	printf("Bunnies: ");
	scanf("%lu", &bunnies);

	printf("%lu bunnies have %lu ears.\n", bunnies, bunnyEars(bunnies));

	return 0;	
}

unsigned long bunnyEars(unsigned long n) {
	// base case: zero bunnies have zero ears
	if (n == 0) return 0;
	// recursive case: n bunnies have 2 ears plus number of ears for n - 1 bunnies
	else return 2 + bunnyEars(n - 1);
}
