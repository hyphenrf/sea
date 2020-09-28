/*
 * a dangling pointer is the source of memleaks.
 *
 * To dangle a pointer is to have zero runtime references of its allocated space
 * without first freeing.
 *
 * example below
 */

#include <stdlib.h>

int main(int argc, char* argv[])
{
	void * p;

	for (int i=0; i<3; i++){
		p = malloc(256);
	}
	/* Now there are 512 bytes of unreachable allocated memory. */
	/* To fix that, add a free() stmt under the loop body. */

	return 0;
}
