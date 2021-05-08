/* One of the few implicit semantics in C is deep-copying local arrays when
 * they're wrapped inside a struct: */

typedef struct wrapper wrapper;
struct wrapper {
	int * array;
};

wrapper
somefun(void)
{
	int a[10];
	wrapper s = {a};
	return s;
}

/* Would successfully return a valid address for wrapper.array despite it being
 * defined locally. This is vital for by-value APIs but is a bit of a surprising
 * behaviour. Because the norm is:
 * 	int * somefun(void) { int a[10]; return a; }
 * that this would throw a warning on compilation and may cause serious stack
 * damage on runtime.
 *
 * To be more precise, what's happening is that an array wrapped in a struct is
 * allowed to not decay. TODO: Find the section in C standard discussing this
 * behaviour. */

/* funnily enough, anonymous objects work too!
 * (C standard calls them compound literals) */
int *
someother(void)
{ 
	return (int[10]){0}; // C standard forbids empty braces in initializers
}
