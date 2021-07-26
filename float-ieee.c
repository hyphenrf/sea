#include <stdio.h>
#include <stdint.h>

/* IEEE754 floats are represented in mem like so:
 *
 *           sign |    exponent     | mantissa
 *   float:  1    | 8  (127 bias)   |       23
 *   double: 1    | 11 (1023 bias)  |       52
 *
 * Floats are converted to from decimal following these steps:
 *
 * 420.69 -> 110100100.101100001010010... -> 1.10100100101100001010010 * 2^8
 *   sign: 0
 *   expo: 8 + 127
 *   mant: 10100100101100001010010
 *   repr: 0 10000111 10100100101100001010010
 *   hexa: 0x43d25852
 *
 * now we try it out with our program */

# ifdef DOUBLEPREC
#   define FLIT(x) x
#   define FMT "l"
#	define BIAS 1023
#	define MANT 52
#	define EXPO 11
#	define F double
#	define U uint64_t
#	define I int64_t
# else
#   define FLIT(x) x##f
#   define FMT
#	define BIAS 127
#	define MANT 23
#	define EXPO 8
#	define F float
#	define U uint32_t
#	define I int32_t
# endif

typedef union floatrep ieee;
union floatrep {
	F f;
	struct {
		U mant : MANT;
		U expo : EXPO;
		U sign : 1;
	};
	U i;
};

int
main ()
{
  ieee num = {.f = FLIT(420.69)};
  printf (
    "number: %.2f\n"
    "floatrep: %#"FMT"x\n"
    "neg-sign: %s\n"
    "exponent: %"FMT"u, without bias: %"FMT"d (both in decimal)\n"
    "mantissa: %#"FMT"x\n"
  , num.f, num.i, num.sign? "true" : "false"
  , num.expo, (I)num.expo - BIAS, num.mant );
  return 0;
}
