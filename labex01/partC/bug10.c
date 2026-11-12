/*  bug10.c
 *
 *  WHAT IT IS SUPPOSED TO DO
 *      Take a greeting, capitalise its first letter, and print it.
 *      The output should be "Hello, world".
 *
 *  WHAT ACTUALLY HAPPENS
 *      The program dies on the line that does the capitalising. No
 *      message, no output, just an abrupt exit.
 *
 *  There is ONE defect. It is not in the letter or the index.
 *  Fix it with the smallest change you can.
 *
 *  Before you change anything: the second variable below is built a
 *  different way from the first, and only one of them is writable.
 *  Work out which, and why, and the fix follows from that.
 */

#include <stdio.h>

int main(void)
{
	char label[] = "greeting: ";
	char *text   = "hello, world";

	text[0] = 'H';

	printf("%s%s\n", label, text);

	return 0;
}
