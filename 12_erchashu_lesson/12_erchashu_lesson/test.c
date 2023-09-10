#define _CRT_SECURE_NO_WARNINGS 1






#include<stdio.h>
#include <math.h>
int main()
{
    int x,y=0;
    scanf("%d", &x);
    while (x > 10)
    {
        y = y + x % 10;
        x = x / 10;
    }
    y = y + x;
    printf("result = %d", y);
	return 0;
}