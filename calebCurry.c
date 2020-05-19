/*
 * so, I'm going to be learning C from the youtuber
 * Caleb Curry for now.
 * So this file will contain all my practice
 */

// Video no.11 Let's get some user input
#include <stdio.h>

// Video no.28 how to use bool datatype instead of builtin _Bool 
#include <stdbool.h> // you just include this lol
// bool also supports true and false keywords instead of 0s and 1s


void scans()
{
    int x;
    printf("enter your shit value: ");
    scanf("%d", &x); // %i and %d are used interchangeably. But with scanf
                     // you can actually read 0xHEX nums using %i
    printf("your value is: %d\n", x);       

}

void floatingIO()
{
    double boi; // float type numbers are stored in memory as double unless 
                // you specify that they're float like this: 1.234f
    /* 
     * if you would have an equation float price = 7.50 / 2.50; 
     * versus float price = 7.50f / 2.50f; 
     * then the result might differ due to different resolution. 
     * In the first case the compiler will have to do the calculation as double
     * then convert the result to float. In the second case the calculation is 
     * done in float. 
     *
     * Note that if only one value is double the whole thing is calculated as 
     * double. The C compiler is not allowed to optimize that away as their 
     * rounding would differ. 
     * So floatvarA = floatvarB / 2.0 performs worse than with 2.0f.
     *
     */
    printf("floating stuff: ");
    scanf("%lf", &boi); // lf is double, Lf is long double, f is float
                        // boi is double, so we use lf
    boi = boi/2.0;
    printf("%.2lf\n", boi/2.0);


    
}

void strings()
{
    //strings are null terminated arrays of chars
    
    /* char name[6];
     * name = {'h', 'a', 'n', 'n', 'a', '\0'};
     * you can't do this.
	 * in c but not c++ [citation?] you can due psuedo strings like this:
	 * char name[] = "hanna"; // but you have to include string.h
	 * however, [] is valid syntax without string.h. it means arry by number of
	 * provided elements.
     */
    
    char name[6] = {'h', 'a', 'n', 'n', 'a', '\0'};
    printf("Hello %s!\n", name);

    //two distinct things about character arrays:
    //1- they do not need the address denotion in scanf (array name is a
    //   pointer)
    //2- scanf's %s does not read spaces
    
    char readName[31]; // remember array len = string len +1 because
    // there's a null terminator '\0'
    // using scanf + a buffer directly is vulnerable to a class of bugs called
    // buffer overflow
    
    printf("Hello, enter a name: ");
    scanf("%s", readName); // there is a directive '%[^\n]' which CAN read spaces
    printf("Hello %s!\n",readName);

}


void test();

int main()
{

    //scans();
    
    //strings();

    floatingIO();


    //test();
        
    return 0;
}

void test()
{
        printf("%c",'h');
        printf("%c",'\n');
}
