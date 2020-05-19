#include <stdio.h>
/* 
** A named array is a very simple concept in which we disambiguate
** array indicies by storing them in an enum
** this is useful from a programmer's perspective but should ultimately behave
** just as you'd expect a regular array to.
**
** NOTE: that this is not your usual hashmap because there's no way to
** programmatically manipulate the defined symbols. To the compiler they're
** still just numbers.
**
** Another way to do this is with macros but enums are nicer
*/

// anonymous enum
enum { A, B, C };

int main(int argc, char* argv[])
{
	int tokens[3] = {
		[A] = 69,
		[B] = 420,
		[C] = 9001
	};
	for (int i=0; i<3; i++)
		printf("%d\n", tokens[i]);

	return 0;
}
