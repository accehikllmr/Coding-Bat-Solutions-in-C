/*
 * Given a non-negative int n, return the sum of its digits recursively (no loops). Note 
 * that mod (%) by 10 yields the rightmost digit (126 % 10 is 6), while divide (/) by 10 
 * removes the rightmost digit (126 / 10 is 12).
 *
 * sumDigits(126) → 9
 * sumDigits(49) → 13
 * sumDigits(12) → 3
 */

#include<stdio.h>

unsigned long sumDigits(unsigned long);

int main() {

	unsigned long digits = 0;
	printf("Digits: ");
	scanf("%lu", &digits);

	printf("Sum of %lu digits = %lu\n", digits, sumDigits(digits));

	return 0;
}

unsigned long sumDigits(unsigned long n) {

	if (n < 10) return n;
	else return n % 10 + sumDigits(n / 10);
}
