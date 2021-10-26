/* One of the few implicit semantics in C is deep-copying local arrays when
 * they're wrapped inside a struct: */

typedef struct wrapper wrapper;
struct wrapper {
	int array[10]; // size MUST be defined in the struct
};

wrapper
somefun(void)
{
	wrapper s = {0}; // array MUST be declared inside the compound literal
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
 * allowed to not decay, and allowed to be a return type. Structs and unions etc
 * have value semantics unlike bare arrays. */

