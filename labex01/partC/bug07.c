/*  bug07.c
 *
 *  WHAT IT IS SUPPOSED TO DO
 *      Process five batches of work. Each batch needs a 1 MB scratch
 *      buffer, which is finished with by the end of the batch.
 *
 *  WHAT ACTUALLY HAPPENS
 *      It prints the right thing and exits with status 0. Nothing
 *      looks wrong at all.
 *
 *      Open Task Manager (Details tab, Memory column) and raise
 *      BATCHES to 400 before you run it again.
 *
 *  There is ONE defect. Fix it with the smallest change you can, and
 *  do not restructure the program.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BATCHES     5
#define SCRATCH  (1024 * 1024)

int main(void)
{
	char *scratch = NULL;

	for (int b = 1; b <= BATCHES; b++) {
		scratch = malloc(SCRATCH);

		if (scratch == NULL) {
			printf("out of memory in batch %d\n", b);
			return 1;
		}

		memset(scratch, 0, SCRATCH);
		printf("batch %d done\n", b);
	}

	free(scratch);

	return 0;
}
