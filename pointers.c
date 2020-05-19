#include "pointers.h"

void pain()
{
	void* g; 
	// pointers can be void and general-purpose, but that limits your
	// ability to do pointer arithmatic and you'll have to typecast them with
	// (type*) p when attempting to use em in type-specific shit like printf
	int* p; // pointers take the same type as their variable
	int  x; // init the variable

	p = &x; // to point at x, you need to use the address operator &
	x =  5;
	// note: address operator can never be used lhs, as so: &x = 0xdeadbeef

	g = p; // will this work? yes. *g = *p won't. (not without type casting)
	// to disallow pointer aliasing, add the keyword `restrict` to the pointer
	// declaration.

	printf("x's value:\t%d\n", 		 x);
	printf("x's address:\t%p\n", 	&x);
	printf("p's value:\t%p\n", 		 p); // prints x's address
	printf("p's deref val:\t%d\n", 	*p); // prints x's value
	// printf("x's deref val:\t%d\n", 	*x); // shouldn't work
	/* 
	 * at compile time:
	 * error: invalid type argument of unary ‘*’ (have ‘int’)
	 * because x isn't a pointer
	 */
	printf("p's address:\t%p\n", 	&p); // prints p's address!!

	printf("g's value :\t%p\n", g);
	printf("g's deref val:\t%d\n", *((int*)g) ); //won't work without casting

	// let's have fun:
	
	puts("=========================");
	puts("*p = 10;");
	*p = 10;

	printf("x's value:\t%d\n", 		 x);
	//printf("x's address:\t%d\n", 	&x);
	//printf("p's value:\t%d\n", 		 p);
	//printf("p's deref val:\t%d\n", 	*p);
	//printf("p's address:\t%d\n", 	&p);
	
/*
	puts("=========================");
	puts("p = 10;");
	p = 10; // compiles with a warning

	printf("x's value:\t%d\n", 		 x);
	//printf("x's address:\t%d\n", 	&x);
	printf("p's value (no longer x's addr):\t%d\n", p);
	printf("p's deref val:\t");
	//printf("%d", *p); // this segfaults. 
	// cause p points at addr 0x00000000000a
	printf("\n");
	//printf("p's address:\t%d\n", 	&p);
*/
	
}



/*
 * C's functions are called by value, not reference. And the function scope is
 * private and has no effect over global scope.
 * To get around this and introduce mutability, we build the function to handle
 * pointers instead of values.
 * In this example I'll construct two functions, swap and pswap, and we'll try
 * to see the difference in their effect
 */

void swap(int a, int b)
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

void pswap(int* a, int* b)
{
	int tmp;
	tmp = *a;
	*a = *b; // remember *p = *g and how it didn't work?
	*b = tmp;
}

void swaptest()
{

	puts("===============================");

	int a, b;
	a = 10;
	b = 69;

	printf("before swapping: a = %d, b = %d\n", a, b);

	swap(a, b);
	printf("after swap: a = %d, b = %d\n", a, b);
	
	pswap(&a, &b); // another way is to pass a,b pointers instead of addresses
	printf("after pswap: a = %d, b = %d\n", a, b);
}




int main()
{
	pain();
	swaptest();
	return 0;
}
