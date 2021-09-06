#include <stdio.h>
#define SIZE 1000001
int PrimeArray[SIZE];

int main(void)
{
    int m, n, i, j;
    scanf("%d %d", &m, &n);

    for (i = 2; i < SIZE; i++)
        PrimeArray[i] = 1;
    PrimeArray[0] = 0;
    PrimeArray[1] = 0;
    for (i = 2; i < SIZE / i; i++)
    {
        if (PrimeArray[i] == 0)
            continue;
        for (j = i * i; j < SIZE; j += i)
        {
            if (j % i == 0)
                PrimeArray[j] = 0;
        }
    }
    for (i = m; i <= n; i++)
    {
        if (PrimeArray[i] == 1)
            printf("%d\n", i);
    }
    return 0;
}