/*  main.c - the driver.
 *
 *  Part of the provided material for Laboratory Exercise 01, Part A.
 *
 *  Do not rewrite this file. It is correct as it stands, and it is the
 *  specification for everything else: whatever main.c asks for is what
 *  the rest of the program has to provide.
 *
 *  When the program is finished, this is exactly what it should print:
 *
 *      PS C:\datastruct\partA> .\stats.exe < input.txt
 *      [stats] read 10 values
 *      count = 10
 *      sum   = 220
 *      min   = 3
 *      max   = 61
 *      range = 58
 *      mean  = 22.00
 */

#include <stdio.h>
#include "stats.h"

#define MAX 32

int main(void)
{
	int a[MAX];
	int n = readValues(a, MAX);

	if (n == 0) {
		printf("no values read\n");
		return 1;
	}

	printf("count = %d\n", n);
	printf("sum   = %d\n", sumOf(a, n));
	printf("min   = %d\n", minOf(a, n));
	printf("max   = %d\n", maxOf(a, n));
	printf("range = %d\n", rangeOf(a, n));
	printf("mean  = %.2f\n", meanOf(a, n));

	return 0;
}
