/*  bug01.c
 *
 *  WHAT IT IS SUPPOSED TO DO
 *      Show a value, the address it lives at, and the same value read
 *      back through a pointer. The first and third numbers should
 *      both be 42.
 *
 *  WHAT ACTUALLY HAPPENS
 *      The third line prints an enormous number instead of 42. It is
 *      a different enormous number on each run, and it does not crash.
 *
 *  There is ONE defect. Fix it with the smallest change you can, and
 *  do not restructure the program.
 *
 *  Compile with -Wall. The compiler has an opinion about this one,
 *  and the opinion names both types involved.
 */

#include <stdio.h>

int main(void)
{
	int x = 42;
	int *p = &x;

	printf("x       = %d\n", x);
	printf("address = %p\n", (void *)&x);
	printf("value   = %d\n", p);

	return 0;
}
