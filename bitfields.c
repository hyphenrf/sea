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
 * You can also do it without bitfields without two much trouble. 
 * Just calculate the result and (result &(2 power n - 1)) */


