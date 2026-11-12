/*  bug05.c
 *
 *  WHAT IT IS SUPPOSED TO DO
 *      Fill a heap array of 10 ints with squares, print the total,
 *      and release the block. The total should be 285.
 *
 *  WHAT ACTUALLY HAPPENS
 *      The total prints, and it is correct. Then the program aborts
 *      on the way out.
 *
 *      Note where it dies, and note that the line it dies on is not
 *      the line that is wrong. That is the whole character of this
 *      class of bug, and it is why you cannot debug it by staring
 *      at the crash.
 *
 *  There is ONE defect. Fix it with the smallest change you can, and
 *  do not restructure the program.
 */

#include <stdio.h>
#include <stdlib.h>

#define N 10

int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);   /* unbuffered: see output before a crash */

	int *a = malloc(N * sizeof(int));
	int total = 0;

	if (a == NULL)
		return 1;

	for (int i = 0; i <= N; i++)
		a[i] = i * i;

	for (int i = 0; i < N; i++)
		total += a[i];

	printf("total = %d\n", total);

	free(a);
	a = NULL;

	return 0;
}
