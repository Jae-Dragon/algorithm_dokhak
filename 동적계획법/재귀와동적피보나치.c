#include <stdio.h>
#define LENGTH 100

int fibonacciNumbers[100];

int fibonacci(int n);
int Dynfibonacci(int n);
int DynRecfibonacci(int n);
void initfibonacci();

int main()
{
    int n;
    for (n = 0; n <= 10; n++)
    {
        printf("%d ", Dynfibonacci(n));
    }

    return 0;
}

int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int Dynfibonacci(int n)
{
    int i;
    for (i = 0; i <= n; i++)
    {

        if (i == 0)
        {
            fibonacciNumbers[i] = 0;
        }
        else if (i == 1)
        {
            fibonacciNumbers[i] = 1;
        }
        else
        {
            fibonacciNumbers[i] = fibonacciNumbers[i - 1] + fibonacciNumbers[i - 2];
        }
    }

    return fibonacciNumbers[n];
}

int DynRecfibonacci(int n)
{

    if (fibonacciNumbers[n] == -1)//만약 그 배열이 비어있다면
    {
        if (n == 0)
        {
            fibonacciNumbers[n] = 0;
        }
        else if (n == 1)
        {
            fibonacciNumbers[n] = 1;
        }
        else
        {
            fibonacciNumbers[n] = DynRecfibonacci(n - 1) + DynRecfibonacci(n - 2);
        }
    }
    //안비어있으면 바로 리턴
    return fibonacciNumbers[n];
}
void initfibonacci()
{
    for (int i = 0; i < LENGTH; i++)
    {
        fibonacciNumbers[i] = -1;
    }
}
