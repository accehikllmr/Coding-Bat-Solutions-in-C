/* Given an array of ints, compute recursively if the array contains a 6. We'll use the convention of considering 
 * only the part of the array that begins at the given index. In this way, a recursive call can pass index+1 to 
 * move down the array. The initial call will pass in index as 0.
 *
 * array6([1, 6, 4], 0) → true
 * array6([1, 4], 0) → false
 * array6([6], 0) → true
 */

#include<stdio.h>

// passing pointers to beginning and end of array of integers, otherwise unclear when to stop checking
int array6(unsigned long *, unsigned long *);

int main() {

	unsigned long size = 0;
	printf("Size of array: ");
	scanf("%d", &size);

	unsigned long array[size];
	for (unsigned long i = 0; i < size; i++) {
		printf("[%lu] = ", i);
		scanf("%lu", &array[i]);
	}

	char *result = (array6(array, array + size) == 1) ? "true" : "false";

	printf("array contains number 6 as an element: %s\n", result);

	return 0;
}

int array6(unsigned long *begin, unsigned long *end) {

	// iterate until begin pointer reaches end pointer, lazy evaluation ends when and if 6 is found	
	if (begin != end) return (*begin == 6) || array6(begin + 1, end);
	// once end is reached, if not 6 found return 0 (i.e. all recursive calls return 0)
	else return 0;
}
