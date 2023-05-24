#include <stdio.h>

int fibonacciNumbers[100];

int fibonacci(int n);
int Dynfibonacci(int n);

int main()
{
    int n;
    for(n = 0; n <= 8; n++){
        printf("%d ",Dynfibonacci(n));
    }

    return 0;
}

int fibonacci(int n)
{
    if(n == 0){
        return 0;
    } else if(n==1){
        return 1;
    } else{
        return fibonacci(n-1) + fibonacci(n-2);
    }    
}

int Dynfibonacci(int n)
{
    int i;
    for(i = 0; i <= n; i++){

        if(i == 0){
            fibonacciNumbers[i] = 0;
        } else if(i == 1){
            fibonacciNumbers[i] = 1;
        } else{
            fibonacciNumbers[i] = fibonacciNumbers[i-1] + fibonacciNumbers[i-2];
        }
    }

    return fibonacciNumbers[n];
}
