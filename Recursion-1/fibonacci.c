/*
 * The fibonacci sequence is a famous bit of mathematics, and it happens to have a recursive definition. The first two values in the sequence are 0 and 1 (essentially 2 base cases). Each subsequent value is the sum of the previous two 
 * values, so the whole sequence is: 0, 1, 1, 2, 3, 5, 8, 13, 21 and so on. Define a recursive fibonacci(n) method that returns the nth fibonacci number, with n=0 representing the start of the sequence.
 *
 * fibonacci(0) → 0
 * fibonacci(1) → 1
 * fibonacci(2) → 1
 */

#include<stdio.h>

unsigned long fibonacci(unsigned long);

int main() {
	// initializing to zero, to avoid garbage values
	unsigned long term = 0;
	printf("Fibonacci term: ");
	scanf("f%lu", &term);
	
	printf("f%lu = %lu\n", term, fibonacci(term));
	
	return 0;
}

unsigned long fibonacci(unsigned long n) {

	// base case: 0th and 1st terms are themselves
	if (n == 0 || n == 1) return n;
	// recursive case: nth term is sum of two previous terms
	else return fibonacci(n - 1) + fibonacci(n - 2);
}
