/*
 * Although used for coercion on more typesafe languages, unions in C have a
 * more profound role: They help create both a way to destruucture data, and
 * create ad-hoc polymorphism.
 */
#include <stdio.h>
#include <stdint.h>

/* Coercion example: */
union float_internal_rep {
	int   i32;
	float f32;
};

/* Polymorphism example: */
enum typ { INT64, DOUBLE, CHAR8 };
struct poly {
	enum typ poly_t;
	union {
		long   i64;
		double f64;
		char c8[8];
	};
};

/* Destructure example */
union data {
	struct {
		unsigned byte0:8;
		unsigned byte1:8;
		unsigned byte2:8;
		unsigned byte3:8;
	};
	unsigned bytes;
};

void polymorphic(struct poly *); /* SEE below */
int main() {

	/* coercion */
	/* XXX: UB: 
 	 * C standard only defines accessing the most recently modified union
 	 * field; accessing any other field is undefined but compiler writers agree
 	 * that it's best used for coercion.
 	 */
	union float_internal_rep f;
	f.f32 = 1.2345f;
	printf("0x%X\n", f.i32); /* XXX: UB */
	

	/* polymorphism */
	struct poly t;

	t.poly_t = INT64;
	t.i64    = 42L;
	polymorphic(&t);

	t.poly_t = CHAR8;
	t.c8[0] = 'H';
	t.c8[1] = 'E';
	t.c8[2] = 'L';
	t.c8[3] = 'L';
	t.c8[4] = 'O';
	polymorphic(&t);


	/* deconstruction */
	union data word;
	word.bytes = 0xdeadbeef;
	word.byte2 = 0xcc;
	printf("0x%X\n", word.bytes);

	return 0;
}

void
polymorphic(struct poly *S)
{
	switch (S->poly_t) {

		case INT64:
			printf("long! %ld\n", S->i64);
			break;

		case DOUBLE:
			printf("double! %lf\n", S->f64);
			break;

		case CHAR8:
			puts("char!");
			puts(S->c8);
			break;
	}
}
