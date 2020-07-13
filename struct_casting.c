/*
 * So this is really cool and I should've figured it out way sooner. It makes so
 * much sense!
 *
 * you can move around a pointer to a "public" struct that's a member to another
 * private one, and to access the private one you just cast that pointer
 *
 */

#include <stdio.h>

struct pub_s {
	int a;
	char b[128];
};

struct priv_s {
	struct pub_s pub; /* NOTE: has to be at the beginning to share the same pointer! */

	char secret[128];
};


int main(void) {
	
	struct priv_s private = {
		.pub = {
			.a = 9,
			.b = "thousand!"
		},
		.secret = "cool secret!"
	};
	struct pub_s *public  = &private.pub;

	printf("it's over %d %s\n", public->a, public->b);
	printf("also:\n");
	printf("%s\n", ((struct priv_s*) public)->secret);

	return 0;
}
