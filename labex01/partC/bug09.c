/*  bug09.c
 *
 *  WHAT IT IS SUPPOSED TO DO
 *      Fill a heap array with the first 6 multiples of 7, print them,
 *      then release the memory once, at the end.
 *
 *  WHAT ACTUALLY HAPPENS
 *      It aborts partway through the filling loop, usually on the
 *      second time around.
 *
 *  There is ONE defect. Fix it with the smallest change you can, and
 *  do not restructure the program.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);   /* unbuffered: see output before a crash */

	int n = 6;
	int *a = malloc(n * sizeof(int));

	if (a == NULL)
		return 1;

	for (int i = 0; i < n; i++) {
		a[i] = (i + 1) * 7;
		free(a);
	}

	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);

	printf("\n");

	return 0;
}
