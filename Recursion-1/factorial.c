/*
 * Given n of 1 or more, return the factorial of n, which is n * (n-1) * (n-2) ... 1. Compute the result recursively (without loops).
 * factorial(1) → 1
 * factorial(2) → 2
 * factorial(3) → 6
*/

#include<stdio.h>
#include<stdlib.h>

// both returned values and parameters are of the same kind, since recursion requires function to take in increasingly large value
long unsigned factorial(long unsigned);

int main() {

	// using long unsigned, to allow storage of larger values, since factorial increases faster than exponential
	long unsigned number = 0;
	scanf("%d!", &number);
	// using conversion format for long unsigned
	printf("%lu! = %lu\n", number, factorial(number));
	
	return 0;
}

long unsigned factorial(long unsigned n) {
	// base case, factorial of 0 is equal to 1, could also stop at 1, but this limits possible argument values
	if (n == 0) return 1;
	// recursive case: factorial of some integer it that number multiplied by the factorial of the next smallest integer
	else return n * factorial(n - 1);	
}
