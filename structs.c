#include <stdio.h>

/* Structs are product-types
 * Sometimes called records
 * In C they're used to implement any heterogenous collection, and are used also
 * as the building block of most datastructures. */

/* the Plan-9 convention of defining structs is to treat them as types.
 * for extra clarity, (and verbosity), you might not want to do that. */

typedef struct mytype mytype; // if so, you might want to comment this line out.
struct mytype {
	int a;
	int b;
	char *c;
}/* default = {some default values} */;


int main(int argc, char* argv[])
{
	char *str = "hello world";
	struct mytype s = {.c = str}; // fun fact: you may not specify all fields
	//                  ^-- this initialization syntax is new (C99 I believe?}
	mytype *p = &s; // thanks to typedef we can omit `struct' keyword
	
	printf("%d %d %s\n", s.a, p->b, s.c);

	return 0;
}
