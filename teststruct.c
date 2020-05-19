#include <stdio.h>

int meaning(int a) {
		return 42*a / a;
}

struct hummus {
	int id;
	int (*meaninig)(int a);
//};
//const struct hummus DEFAULT_HUMMUS = {0, &meaning}
} DEFAULT_HUMMUS = {0, &meaning};

int main(int argc, char* argv[])
{
	struct hummus s = DEFAULT_HUMMUS;
	int result;
	
	result = s.meaninig(5);
	printf("%d\n", result);
	return 0;
}
