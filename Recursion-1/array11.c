/* Given an array of ints, compute recursively the number of times that the value 11 appears in the array. We'll 
 * use the convention of considering only the part of the array that begins at the given index. In this way, a 
 * recursive call can pass index+1 to move down the array. The initial call will pass in index as 0.
 *
 * array11([1, 2, 11], 0) → 1
 * array11([11, 11], 0) → 2
 * array11([1, 2, 3, 4], 0) → 0
 */

#include<stdio.h>

int array11(int *, int *);

int main() {

	// user input for size of array
	int size = 0;
	printf("Size of array: ");
	scanf("%d", &size);

	// populating array with values from user
	int numbers[size] = {};
	for (int i = 0; i < size; i++) {
		printf("numbers[%d] = ", i);
		scanf("%d", &numbers[i]);
	}

	// passing ptr to memory address for first array element and ptr to memory address after last array element
	printf("11 appears %d times in the array\n", array11(numbers, numbers + size));

	return 0;
}

int array11(int *ptr, int *end) {
	
	// ends only when reaching memory address after last element of array
	if (ptr != end) {
		
		return ((*ptr == 11) ? 1 : 0) + array11(ptr + 1, end);
	}

	// for last function call, otherwise returns garbage value
	return 0;
}
