#include <stdio.h>
/* 
 * Static fields in C retain their value across the program's runtime.
 *
 * In process structure: static vars, like globals, are stored in the .data
 * section.. However, unlike globals, their scope is limited to where they were
 * declared.
 * Remember that normal scoped vars are stored in registers and/or on stack/heap.
 *
 * We can use them the same way we'd use python's generators. Creating an opaque
 * function interface. for example:
 */
	
int
num_generator(void)
{
	/* static local variables and global variables without the static keyword, are
 	 * initialized to either zero, or their defined value. */

	static int arthur; //scoped and inaccessible, initialized to 0 by default
	/* Note: even if you manually init this to 0, it will only be defined once and
 	 * its value will change on each subsequent call without being reset to 0 on
 	 * each call. */
	return arthur++;
}

int main(int argc, char* argv[])
{
	printf("%d\n", num_generator()); //0
	printf("%d\n", num_generator()); //1
	printf("%d\n", num_generator()); //2
	printf("%d\n", num_generator()); //3
	printf("%d\n", num_generator()); //4
	//...
	//upto INT_MAX
	
	return 0;
}

/* The static functions are a much simpler concept: A static function is one
 * which has its scope limited to the file it's declared in. That allows reuse
 * of function names across a project */

static int hello(void) { return 5; }

/* Try combining extern and static; the compiler will yell at you. */
