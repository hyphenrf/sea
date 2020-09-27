/* testing functions in structs */

#include <stdio.h>

int meaning(int a) {
		return 42*a / a;
}
void nothing_burger(void){};

struct hummus {
	int id;
	int (*meaninig)(int a);
//};
//const struct hummus DEFAULT_HUMMUS = {0, &meaning}
} DEFAULT_HUMMUS = {0, &meaning};

typedef struct{void (*nothing_burger)(void);} nothing;
// `nothing` is sort-of class now

int main(int argc, char* argv[])
{
	struct hummus s = DEFAULT_HUMMUS;
	nothing news;
	int result;
	
	result = s.meaninig(5);
	printf("%d\n", result);
	news.nothing_burger();
	return 0;
}
