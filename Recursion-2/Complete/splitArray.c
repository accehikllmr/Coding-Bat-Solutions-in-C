/* Given an array of ints, is it possible to divide the ints into two groups, so that the sums of the two groups 
 * are the same. Every int must be in one group or the other. Write a recursive helper method that takes whatever 
 * arguments you like, and make the initial call to your recursive helper from splitArray(). (No loops needed.)
 *
 * splitArray([2, 2]) → true
 * splitArray([2, 3]) → false
 * splitArray([5, 2, 3]) → true
 */

#include<stdio.h>
#include<stdlib.h>

int arraySum(int *, int*);
int splitArray(int *, int *, int *, int *, int);
int splitArrayHelper(int *, int *, int *, int *, int, int, int);

int main() {

	int size = 0;
	printf("Size of array: ");
	scanf("%d", &size);

	int *inputArray = (int *)calloc(size, sizeof(int));
	for (int i = 0; i < size; i++) {
		printf("[%d] = ", i);
		scanf("%d", inputArray + i);
	}

	int *leftArray = (int *)calloc(size, sizeof(int));
	int *rightArray = (int *)calloc(size, sizeof(int));
	int *endInputArray = inputArray + size;

	char *result = (splitArray(inputArray, endInputArray, leftArray, rightArray, size) != 0) ? "CAN" : "CANNOT";

	printf("array %s be split into two groups, such that each group has the same sums of elements\n", result);

	free(inputArray);
	free(leftArray);
	free(rightArray);

	return 0;
}

/* recursively iterates through array by incrementing ptr to first element until reaching ptr to last element */
int arraySum(int *from, int *to) {
	// ptr reaches last element of array, so recursive calls end, also works for empty array (i.e. sum = 0)
	if (from == to) return *from;
	// add value of dereferenced ptr to recursive call
	else return *from + arraySum(from + 1, to);
}

/* returns result of helper function */
int splitArray(int *array, int *arrayEnd, int *left, int *right, int size) {
	// passing ptr to first and last elements of array, and ptrs to pair of new arrays with insertion index
	return splitArrayHelper(array, arrayEnd, left, right, 0, 0, size); 
}

/* */
int splitArrayHelper(int *from, int *to, int *left, int *right, int leftIndex, int rightIndex, int size) {
	// stores result of given recursive call, and all other recursive calls made from this call (see below)
	int result = 0;
	// no need to evaluate empty array case separately, since unmodified initialized arrays will have same sum
	// iterating over entire size, regardless of number of elements added from array (i.e. rest are 0s)
	if (from == to) {
		// increments resutlt and goes back up the stack to previous recursive call, check size to prevent invalid memory access
		result += (size != 0) ? arraySum(left, left + size - 1) == arraySum(right, right + size - 1) : 1;
	}
	// pointer traversing array has not yet reached memory address located after end of array
	else {
		// place element at array index in left array (first option) at left index
		*(left + leftIndex) = *from;
		// recursive call to place following elements in array, incrementing left index since added element
		result += splitArrayHelper(from + 1, to, left, right, leftIndex + 1, rightIndex, size);
		// reset value to zero for index, since did not return true when comparing sums
		*(left + leftIndex) = 0;

		// repeat of above algorithm, but for adding elements to right array
		*(right + rightIndex) = *from;
		result += splitArrayHelper(from + 1, to, left, right, leftIndex, rightIndex + 1, size);
		*(right + rightIndex) = 0;
	}
	// algorithm not efficient, will traverse entire binary tree even after finding result (i.e. result > 1)
	return result != 0;
}

