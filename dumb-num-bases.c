#include <stdio.h>
#include <stdint.h>


#define BITS 3
#define CELL uint8_t


enum CONTAINER_T {
	BINARY  = 2,
	TERNARY = 3,
	OCTAL   = 8,
	DECIMAL = 10,
};

typedef struct CONTAINER {
	enum CONTAINER_T tag;
	CELL val[BITS];
} container;


void print(container);
container twos(container);
container add(container, container);


void
print(container num)
{ 
	for (int i=0; i<BITS; i++) printf("%d", num.val[i]);
}

container
twos(container num)
{
	container one = { .tag = num.tag, .val = {[BITS-1]=1} };
	container result = { .tag = num.tag };
	
	for (int i=0; i<BITS; i++)
		result.val[i] = num.tag - num.val[i] - 1;
	return add(result, one);
}

container
add(container lvalue, container rvalue)
{
	if (lvalue.tag != rvalue.tag) {
		puts("Type error: invalid addition of different bases");
		return (container){0};
	}

	container result = { .tag = lvalue.tag };

	CELL *o, *l, *r, carry = 0;
	o = result.val;
	l = lvalue.val;
	r = rvalue.val;

	for (int i = BITS-1; i>-1; i--) {
		o[i]  = l[i] + r[i] + carry;
		carry = 0;
		if (o[i] >= result.tag) {
			carry = o[i] / result.tag;
			o[i]  = o[i] % result.tag;
		}
	}
	return result;
}


int main(int argc, char* argv[])
{
	container l = { .tag = DECIMAL, .val = {[BITS-3] = 5, 0, 0} };
	container r = { .tag = DECIMAL, .val = {[BITS-3] = 3, 2, 9} };

	/* l = twos(l); // twos 500(10) -> 500 */
	/* r = twos(r); // twos 329(10) -> -329 */
	print(l); printf(" + "); print(r); printf(" = "); print(
		add(l, r)
	); puts("");

	return 0;
}
