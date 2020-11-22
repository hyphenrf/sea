/* scale_bugs.c
 * Copyright (C) 2020 devel <hyphens@pm.me>
 */

/* #include "scale_bugs.h" */

struct entrypoint {
	int size;
	char bogus[25];
} default_struct = {
	sizeof(struct entrypoint),
	{0}
};

int main(int argc, char* argv[])
{
	struct entrypoint entry = default_struct;
	struct entrypoint *ptr  = &entry;
	memcpy(ptr->bogus, "Hello world foo bar baz funk etc",32); /* XXX: overflow, won't stop at 25th byte! */
	ptr += ptr->size; /* size = 32 so this is 32*32 increment !!! */
	/* the correct syntax is ++ptr because scaling is auto. always remember that.
	 * if you want finer shifts, define a new ptr of smaller size and cast cast cast. */
	/* char* reader = (void*) ptr; */
	/* reader += ptr->size; */
	return 0;
}
