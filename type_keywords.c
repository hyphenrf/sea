
/* STORAGE CLASSES */
extern int a; /* global, usually defined in .h files, initialized to 0
							 * a variable with program-wide scope no matter where it was
							 * declared, functions with external linkage etc.. */
static int b; /* local, persistent between function calls, initialized to 0 */

void local_scope() {
	auto int c; /* all local variables are auto, initialized to garbage, it is
							 * redundant */
	register int d; /* limited number of small often-used variables can be
									 * stored in CPU registers for performance, initialized to
									 * garbage */
}

/* TYPE QUALIFIERS */
int const e; /* immutable (can still be mutated with pointers,
							* but not assignment */
int volatile f; /* changing without explicit assignment, like current time etc */
/* const and volatile ARE compatible, a const volatile int can be changed by the
 * hardware but not the program. */
