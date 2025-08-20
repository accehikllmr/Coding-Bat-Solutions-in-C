/* Given a non-negative int n, compute recursively (no loops) the count of the occurrences 
 * of 8 as a digit, except that an 8 with another 8 immediately to its left counts double, 
 * so 8818 yields 4. Note that mod (%) by 10 yields the rightmost digit (126 % 10 is 6), 
 * while divide (/) by 10 removes the rightmost digit (126 / 10 is 12).
 *
 * count8(8) → 1
 * count8(818) → 2
 * count8(8818) → 4
 */

#include<stdio.h>

unsigned long count8(unsigned long);

int main() {

	unsigned long digits = 0;
	printf("Digits: ");
	scanf("%lu", &digits);

	printf("Count of 8s in %lu = %lu\n", digits, count8(digits));

	return 0;
}

unsigned long count8(unsigned long n) {

	if (n == 8) return 1;
	else if (n < 10) return 0;
	else return ((n % 10 == 8) ? 1 : 0) + ((n % 100 == 88) ? 1 : 0) + count8(n / 10);

}
