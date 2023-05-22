
#include <stdio.h>
#pragma warning(disable : 4996)
#include <string.h>
#include <stdlib.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

   while(a!=b)
   {
        if(a > b)
        {
            a -= b;
        }
        else
        {
            b -= a;
        }

   }
   printf("%d", a);

    return 0;
}