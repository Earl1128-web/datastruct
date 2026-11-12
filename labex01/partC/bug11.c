/*  bug11.c
 *
 *  WHAT IT IS SUPPOSED TO DO
 *      Walk a heap array with a pointer instead of an index, printing
 *      each value, then release the block.
 *
 *  WHAT ACTUALLY HAPPENS
 *      All four numbers print correctly. Then the program aborts on
 *      the way out, with a complaint from the C runtime about the
 *      heap.
 *
 *  There is ONE defect. The printing loop is correct -- do not change
 *  it. Fix the program with the smallest change you can.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);   /* unbuffered: see output before a crash */

	int n = 4;
	int *a = malloc(n * sizeof(int));

	if (a == NULL)
		return 1;

	for (int i = 0; i < n; i++)
		a[i] = (i + 1) * 5;

	int *p = a;

	while (p < a + n) {
		printf("%d ", *p);
		p++;
	}

	printf("\n");

	free(p);

	return 0;
}
