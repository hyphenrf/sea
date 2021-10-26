#include <float.h>
#include <stdio.h>
#include <assert.h>
#include <stdint.h>

#ifdef __BYTE_ORDER__
# define LITTLE_ENDIAN (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__)
#else
# define LITTLE_ENDIAN (0x4142 == 'AB') // https://stackoverflow.com/a/9283155/10831589
#endif
static_assert(LITTLE_ENDIAN, "Endianness: LE");

typedef long double f128;
static_assert(sizeof(f128) == 16, "long double is aligned-128 bits");

typedef struct uint128_t u128;
struct uint128_t {
	uint64_t lo;
	uint64_t hi;
};
static_assert(sizeof(u128) == 16, "no padding in a struct of two u64's");

typedef union fud fud;
union fud {
	f128 val;
	u128 repr;
};
static_assert(sizeof(fud) == 16, "no padding in the float-uint union");



#define EACH(i, a) for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++)

int main() {
	f128 floats[] = {LDBL_MAX};
	EACH(i, floats)
		printf("%#lx%lx\n",
				((fud)floats[i]).repr.hi,
				((fud)floats[i]).repr.lo);
	return 0;
}
