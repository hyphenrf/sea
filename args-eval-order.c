/* Argument evaluation order in C is undefined.
 *   prerequisite: type_static.c */

#include <stdio.h>

int sequence(void) {
	static int i;
	return ++i;
}

int main()
{
	printf("eval order: %d, %d, %d\n", sequence(), sequence(), sequence());
	/* gcc:   3, 2, 1
	 * clang: 1, 2, 3
	 * tcc:   1, 2, 3 */
	return 0;
}
