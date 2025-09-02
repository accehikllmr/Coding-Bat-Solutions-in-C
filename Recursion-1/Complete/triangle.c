/*
 * We have triangle made of blocks. The topmost row has 1 block, the next row down has 2 
 * blocks, the next row has 3 blocks, and so on. Compute recursively (no loops or 
 * multiplication) the total number of blocks in such a triangle with the given number of 
 * rows.
 *
 * triangle(0) → 0
 * triangle(1) → 1
 * triangle(2) → 3
 */

#include<stdio.h>

unsigned long triangle(unsigned long);

int main() {

	unsigned long rows = 0;
	printf("Rows in triangle: ");
	scanf("%lu", &rows);

	printf("Triangle with %lu rows has %lu blocks\n", rows, triangle(rows));
	
	return 0;
}

unsigned long triangle(unsigned long n) {

	if (n == 0) return 0;
	else return n + triangle(n - 1);
}
