/*  bug08.c
 *
 *  WHAT IT IS SUPPOSED TO DO
 *      makeSequence() builds an array of n ints holding 1, 2, ... n
 *      and hands it back to main, which prints it and releases it.
 *
 *  WHAT ACTUALLY HAPPENS
 *      On the laboratory machines it crashes before printing
 *      anything. On another compiler it might print garbage, or even
 *      print the right answer once and the wrong one the next time.
 *
 *      A bug that changes its mind between machines is telling you
 *      something specific. Work out what.
 *
 *  There is ONE defect. Fixing it properly means changing where the
 *  memory comes from, not changing the loop.
 *
 *  Compile with -Wall. The compiler has an opinion about this one.
 */

#include <stdio.h>
#include <stdlib.h>

int *makeSequence(int n)
{
	int seq[64];

	for (int i = 0; i < n; i++)
		seq[i] = i + 1;

	return seq;
}

int main(void)
{
	int n = 6;
	int *s = makeSequence(n);

	for (int i = 0; i < n; i++)
		printf("%d ", s[i]);

	printf("\n");

	return 0;
}
