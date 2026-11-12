/*  bug03.c
 *
 *  WHAT IT IS SUPPOSED TO DO
 *      Allocate a buffer, use it, and release it once on the way out.
 *      There are two exits from the middle of the function, and both
 *      have to release the buffer before they leave.
 *
 *  WHAT ACTUALLY HAPPENS
 *      With the value below it prints "small" and then the program
 *      aborts, usually with a message from the C runtime about the
 *      heap. Change LIMIT to 100 and it exits cleanly.
 *
 *  There is ONE defect. Fix it with the smallest change you can, and
 *  do not restructure the program.
 */

#include <stdio.h>
#include <stdlib.h>

#define LIMIT 3

int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);   /* unbuffered: see output before a crash */

	int *buf = malloc(16 * sizeof(int));

	if (buf == NULL)
		return 1;

	for (int i = 0; i < 16; i++)
		buf[i] = i;

	if (buf[15] > LIMIT) {
		printf("small\n");
		free(buf);
	}

	free(buf);

	return 0;
}
