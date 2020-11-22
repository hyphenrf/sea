/* An int sign representation is actually impl-defined!! So you need to make
 * sure when writing portable code that your assumptions are correct. */
#include <stdio.h>

enum { MAGNITUDE = 1, ONES_COMP = 2, TWOS_COMP = 3 };
#define REP(T) ((T) -1 & (T) 3)

int main()
{
	switch (REP(long)) {
		case MAGNITUDE: puts("Magnitude-sign"); break;
		case ONES_COMP: puts("Ones-Complement"); break;
		case TWOS_COMP: puts("Twos-Complement"); break;
		default:        puts("Bogus repr");
	}
	return 0;
}
