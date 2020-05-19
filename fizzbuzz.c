#include <stdio.h>

int main()
{
        int i;
        const char* arr[] = {"fizzbuzz", "%d", "%d", "fizz", "%d", "buzz",\
                "fizz", "%d", "%d", "fizz", "buzz", "%d", "fizz", "%d", "%d"};

        for (i = 1; i <= 100; ++i) 
        {
            printf(arr[i % 15], i);
        }
        return 0;
}
