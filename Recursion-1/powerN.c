/* 
 * Given base and n that are both 1 or more, compute recursively (no loops) the value of 
 * base to the n power, so powerN(3, 2) is 9 (3 squared).
 *
 * powerN(3, 1) → 3
 * powerN(3, 2) → 9
 * powerN(3, 3) → 27
 */

#include<stdio.h>

unsigned long powerN(unsigned long, unsigned long);

int main() {

	unsigned long base = 0, exponent = 0;
	printf("Power expression: ");
	scanf("%lu^%lu", &base, &exponent);

	printf("%lu^%lu = %lu\n", base, exponent, powerN(base, exponent));

	return 0;
}

unsigned long powerN(unsigned long base, unsigned long n) {

	// base cases: exponent of 0 for any base is 1, whereas base of 0 to any exp is 0
	if (n == 0) return 1;
	else if (base == 0) return 0;
	// recursive case: multiply base by itself to the power of exp - 1 (exponent rules)
	else return base * powerN(base, n - 1);
}
