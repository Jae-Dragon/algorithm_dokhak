#include <stdio.h>

int factorial(int n);

int main()
{
    int ans;

    ans = factorial(7);

    printf("%d",ans);

    return 0;
}

int factorial(int n)
{
    if(n == 0){
        return 1;
    } else{
        return n*factorial(n-1);
    }
}
