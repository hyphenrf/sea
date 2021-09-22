/* testing functions in structs */

#include <stdio.h>

// classes are objects that hold pointers to functions as well as data. some classes are able to refer to their `self`

typedef struct hummus hummus;

int meaning(hummus*, int);

struct hummus {
	hummus * self;
	int id;
	int calls;
	int (*method)(hummus*, int);
}
DEFAULT_HUMMUS = {&DEFAULT_HUMMUS, .method = meaning};
// same as:
// const hummus DEFAULT_HUMMUS = {&DEFAULT_HUMMUS, 0, 0, meaning /* or &meaning, both are the same like with arrays */};

int meaning(hummus* self, int a) {
	(self->calls)++;

	return 42 + self->id * a - a * self->id;
}

int main() {
	hummus s = DEFAULT_HUMMUS;
	int result = s.method(&s,5);

	printf("%d, %d\n", result, s.calls);
	return 0;
}
