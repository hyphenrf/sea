/* fldpi instruction is an x86 instruction that only returns the value of PI as
 * with 80-bit aka
 *   (REAL10 : http://www.website.masmforum.com/tutorials/fptute/fpuchap2.htm#real10)
 * precision.
 *
 * Here we use GCC's inline asm syntax */

#include <stdio.h>
#include <assert.h>
#include <stdalign.h>

typedef long double d128;
static_assert(sizeof(d128) == 16 /* && a way to get size without alignment */,
		"long double is 128 bits with alignment, and has 80-bits precision");

d128 fldpi(void) {
	d128 pi;
	asm("fldpi":"=t"(pi));
	return pi;
}

int main () {
	printf("%.100Lg\n", fldpi());
}
