/* Given an array of ints, compute recursively if the array contains somewhere a value followed in the array by 
 * that value times 10. We'll use the convention of considering only the part of the array that begins at the 
 * given index. In this way, a recursive call can pass index+1 to move down the array. The initial call will pass 
 * in index as 0.
 *
 * array220([1, 2, 20], 0) → true
 * array220([3, 30], 0) → true
 * array220([3], 0) → false
 */

#include<stdio.h>
#include<stdlib.h>

int array220(unsigned long *, unsigned long *);

int main() {

	unsigned long size = 0;
	printf("Size of array = ");
	scanf("%lu", &size);

	unsigned long *array = (unsigned long *)calloc(size, sizeof(unsigned long));
	for (unsigned long i = 0; i < size; i++) {
		printf("[%lu] = ", i);
		scanf("%lu", &array[i]);
	}
	
	// end pointer stores memory address of second last element, since this is last possible comparison
	unsigned long *arrayEnd = array + size - 1;

	char *result = (array220(array, arrayEnd) != 0) ? "true" : "false";

	printf("array has consecutive values such that second is 10 times the first: %s\n", result);

	free(array);

	return 0;
}

int array220(unsigned long *read, unsigned long *end) {
	// read pointer reaches end OR it is less than end (i.e. length is 0), disjunction since need single pair
	if (read != end && read < end) return *read * 10 == *(read + 1) || array220(read + 1, end);
	// no matching pairs found
	return 0;
}
