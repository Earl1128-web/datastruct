/*  bug06.c
 *
 *  WHAT IT IS SUPPOSED TO DO
 *      Swap two ints in main. After the call, x should be 2 and y
 *      should be 1.
 *
 *  WHAT ACTUALLY HAPPENS
 *      Nothing. It runs, it exits cleanly, it compiles without a
 *      single warning, and x and y are exactly where they started.
 *
 *  Somebody has already tried to fix this program once. They changed
 *  the parameters and the call site, and both of those are now right.
 *  There is ONE defect left, and it is inside the function.
 *
 *  Fix it with the smallest change you can. Before you do, say out
 *  loud what the three lines in swap() are actually swapping.
 */

#include <stdio.h>

void swap(int *a, int *b)
{
	int *t = a;
	a = b;
	b = t;
}

int main(void)
{
	int x = 1, y = 2;

	printf("before: x = %d, y = %d\n", x, y);
	swap(&x, &y);
	printf("after:  x = %d, y = %d\n", x, y);

	return 0;
}
