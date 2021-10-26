/* array pointers are interesting because they have different decay semantics */

#include <assert.h>

int main(int argc, char** argv)
{
	short a[5];
	short *b[5];
	short (*c)[5];
	static_assert(sizeof(a) == 10, "array of 5 shorts");
	static_assert(sizeof(b) == 40, "array of 5 ptrs");
	static_assert(sizeof(c) == 8,  "1 ptr to array of 5 shorts");
	return 0;
}
