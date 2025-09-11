/* Given an array of ints, is it possible to divide the ints into two groups, so that the sums of the two groups 
 * are the same. Every int must be in one group or the other. Write a recursive helper method that takes whatever 
 * arguments you like, and make the initial call to your recursive helper from splitArray(). (No loops needed.)
 *
 * splitArray([2, 2]) → true
 * splitArray([2, 3]) → false
 * splitArray([5, 2, 3]) → true
 */

#include<stdio.h>

int arraySum(int *, int*);
int splitArray(int *, int *, int *, int *);
int splitArrayHelper(int *, int *, int *, int *, int, int);

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

	char *result = (splitArray(inputArray, endInputArray, leftArray, rightArray) != 0) ? "CAN" : "CANNOT";

	printf("array %s be split into two groups, such that each group has the same sums of elements");

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
int splitArray(int *array, int *arrayEnd, int *left, int *right) {
	// passing ptr to first and last elements of array, and ptrs to pair of new arrays with insertion index
	return splitArrayHelper(array, arrayEnd, left, right, 0, 0); 
}

/* */
int splitArrayHelper(int *from, int *to, int *left, int *right, int leftIndex, int rightIndex) {	
	// no need to evaluate empty array case separately, since unmodified initialized arrays will have same sum
	// iterating over entire size, regardless of number of elements added from array (i.e. rest are 0s)
	if (from == to) {
		// returning value only if true, otherwise will return to line before recursive call
		if (arraySum(left, left + size - 1) == arraySum(right, right + size - 1)) return true;
	}
	// pointer traversing array has not yet reached memory address located after end of array
	else {
		// place element at array index in left array (first option) at left index
		*(left + leftIndex) = *from;
		// recursive call to place following elements in array, incrementing left index since added element
		splitArrayHelper(from + 1, to, left, right, leftIndex + 1, rightIndex);
		// reset value to zero for index, since did not return true when comparing sums
		*(left + leftIndex) = 0;

		// repeat of above algorithm, but for adding elements to right array
		*(right + rigthIndex) = *from;
		splitArrayHelper(from + 1, to, left, right, leftIndex, rightIndex + 1);
		*(right + rigthIndex) = 0;
	}
}

