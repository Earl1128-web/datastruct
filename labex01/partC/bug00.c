/*  bug00.c
 *
 *  WHAT IT IS SUPPOSED TO DO
 *      Allocate room for 8 ints, fill them with 100, 200, ... 800,
 *      print them back, and release the memory.
 *
 *  WHAT ACTUALLY HAPPENS
 *      All eight numbers print, and all eight are correct. Then the
 *      program aborts on the way out.
 *
 *      So the printing is fine and the crash is somewhere else. Note
 *      which line it dies on, then ask what that line has to check
 *      before it can do its job.
 *
 *  There is ONE defect. Fix it with the smallest change you can, and
 *  do not restructure the program.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);   /* unbuffered: see output before a crash */

	int n = 8;
	int *a = malloc(n);

	if (a == NULL) {
		printf("out of memory\n");
		return 1;
	}

	for (int i = 0; i < n; i++)
		a[i] = (i + 1) * 100;

	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);

	printf("\n");

	free(a);
	a = NULL;

	return 0;
}
