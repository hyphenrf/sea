#include <stdio.h>
#include <stdlib.h>

/*
** BITFILEDS are a way in C to make tightly packed binary data.
** They are not particularly the fastest option between using straight-up ints
** or masking. But the syntax is nice.
**
** Common use cases to bit fields are when you want to pack lots of data in an
** int, or when you want to interface with raw hardware that expects bits 
** formatted in a certain way, or when you're emulating smaller architectures.
**
** BEWARE of the differences between a signed and unsigned field.
** NOTE that the first field in a bitfield is the lsb and so on.
** NOTE that even if a struct is initialised with zeroes, padding/alignment
** fields are to always ALWAYS be assumed garbage. Only relevant fields are
** guaranteed zero.
*/

struct {
	/* 1|0 flags */
	unsigned f1 :1;
	unsigned f2 :1;
	/* 0|1|2|3 flag */
	unsigned f3 :2;
	/* -2|-1|0|1 msb is the sign in two's comp when signed */
	signed   f4 :2;
	/* unnamed fields are padding */
	unsigned    :2;
	/* unnamed zero-fields do alignment (?) */
	unsigned    :0;
	unsigned f5 :8;
	/* PLEASE keep track of how many bits you use, as to not end up allocating
 	 * more space than you saved. i.e. ending up allocating 33 bits will allocate
 	 * two ints */
} custom_fields;

/*TIP: unsigned fields can be used as a zero-cost 2 power n modulo. 
 * any overflow resets the field essentially. */
struct {unsigned x:10;} foo;
/* now foo.x will always be n % 1024, but you're not saving any memory really.
 * You can also do it without bitfields without too much trouble. 
 * Just calculate the result and (result &(2 power n - 1)) */


/* struct fields_32 { unsigned  :0, a:4, b:4, :24; }; */

struct fields_32 { /* this should be internally [b][a][16 unused bits]*/
	unsigned :16, a:8, b:8;
};

int main()
{
	struct fields_32 x = {0}; /* seems to work with std=c99 and above */
	struct fields_32 * y = calloc(1, 4); /* to be sure the struct is zeroed */
	x.a = 0xa;
	x.b = 0xb;
	y->a = 0xa;
	y->b = 0xb;

	printf("%08X\n", x);
	printf("%08X\n", *y);

	free(y); /* the tradeoff to being sure it's zeroed is heap alloc */
	return 0;
}
