/*
 * Given a non-negative int n, return the count of the occurrences of 7 as a digit, so for 
 * example 717 yields 2. (no loops). Note that mod (%) by 10 yields the rightmost digit 
 * (126 % 10 is 6), while divide (/) by 10 removes the rightmost digit (126 / 10 is 12).
 *
 * count7(717) → 2
 * count7(7) → 1
 * count7(123) → 0
 */

#include<stdio.h>

unsigned long count7(unsigned long);

int main() {

	unsigned long digits = 0;
	printf("Digits: ");
	scanf("%lu", &digits);

	printf("Count of 7s in %lu digits = %lu\n", digits, count7(digits));

	return 0;

}

unsigned long count7(unsigned long n) {

	// base cases: for single digit values, return 1 if 7 and 0 otherwise
	if (n == 7) return 1;
	else if (n < 10) return 0;
	// recursive case: if rightmost digit is 7, add 1, and call function with rightmost digit removed
	else return ((n % 10 == 7) ? 1 : 0) + count7(n / 10);

}
