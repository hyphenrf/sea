/*
 * What is double-freeing and why is it a problem?
 *
 * It is *NOT* calling free() on a NULL. free() can handle that easily.
 * That essentially means that there's no need at all to di this:
 * >	if (resource)
 * >		free(resource);
 * except on very specific nonstandard C runtimes which crash on free(NULL).. 
 * Like PalmOS
 *
 * double-freeing is when foo is not NULLed after freeing, and is thus operating
 * on unallocated memory, which is undefined. This is also relevant to the
 * sister bug: use after free.
 *
 * >	free(ptr);
 * >	free(ptr);
 *
 * so remember to always NULL your ptrs after calling free() on them.
 *
 * >	free(ptr);
 * >	ptr = NULL;
 */
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	void * ptr = malloc(8);
	printf("ptr: %p\n", ptr);

	free(ptr);
	printf("ptr (1st free): %p\n", ptr);
	free(ptr); /* the double free is undefined behaviour, and a bad idea */
	printf("ptr (2nd free): %p\n", ptr);
	/* actually any use of ptr after free() within the same scope is undefined */

	return 0;
}
