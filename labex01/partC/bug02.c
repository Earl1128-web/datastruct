/*  bug02.c
 *
 *  WHAT IT IS SUPPOSED TO DO
 *      Build a 5-element array on the heap, print its total, release
 *      it, and then report that the work is finished.
 *
 *  WHAT ACTUALLY HAPPENS
 *      The total is right. The line after it prints a number that is
 *      not the total, and changes between runs.
 *
 *  There is ONE defect. Fix it with the smallest change you can, and
 *  do not restructure the program.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n = 5;
	int *a = malloc(n * sizeof(int));
	int total = 0;

	if (a == NULL)
		return 1;

	for (int i = 0; i < n; i++)
		a[i] = (i + 1) * 3;

	for (int i = 0; i < n; i++)
		total += a[i];

	printf("total     = %d\n", total);

	free(a);

	printf("first was = %d\n", a[0]);
	printf("done\n");

	return 0;
}
