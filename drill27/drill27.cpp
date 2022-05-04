#include<stdio.h>

void print_out(char* p, int x)
{
    printf("p is \"%s\" and x is %i\n",p,x);
}

int main()
{
    printf("Hello World!\n");
    {
        char* a = "Hello";
        char* b = "World!";
        printf("%s %s\n", a, b);
        
    }
    print_out("foo",7);
    print_out("abc",10);
}
