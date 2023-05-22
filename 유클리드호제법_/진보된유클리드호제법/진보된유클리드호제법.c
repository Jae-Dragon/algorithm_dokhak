#include <stdio.h>
#pragma warning(disable : 4996)
#include <string.h>
#include <stdlib.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

   while(a%b != 0 && b%a != 0)
   {
        if(a > b)
        {
            a %= b;
        }
        else
        {
            b %= a;
        }

   }
   int t = 0;
   if(a > b) t = b;
   else t = a;

   printf("%d", t);

    return 0;
}