/*  bug04.c
 *
 *  WHAT IT IS SUPPOSED TO DO
 *      Print all six values of the array, one per line, from inside a
 *      function that was handed the array.
 *
 *  WHAT ACTUALLY HAPPENS
 *      It prints two of them and stops. The array still has six.
 *
 *  There is ONE defect. Fix it with the smallest change you can.
 *  You may change the function's parameter list if you have to --
 *  but if you do, you must be able to say why it was not enough
 *  to fix the body.
 */

#include <stdio.h>

void printAll(int arr[])
{
	int count = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < count; i++)
		printf("  [%d] = %d\n", i, arr[i]);
}

int main(void)
{
	int a[6] = {11, 22, 33, 44, 55, 66};

	printf("the array holds %d ints\n", (int)(sizeof(a) / sizeof(a[0])));
	printAll(a);

	return 0;
}
