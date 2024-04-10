#include <stdio.h>

int add(int x, int y)
{
    int s = x + y;
    return s;
}

int main()
{

    int a = 10;
    int b = 20;

    int s = add(a, b);

    printf("%d", s);

    return 0;
}