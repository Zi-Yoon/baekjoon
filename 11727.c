#include <stdio.h>
#include <stdlib.h>

int combination(int n)
{
    return (n * (n - 1)) % 10007;
}

int factorial(int n)
{
    return n * factorial(n - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    long long sum[1001]={0,1,3,5,};
    for (int i = 4; i < 1001; i++)
    {
        sum[i] = (sum[i-1] + sum[i-2]*2) % 10007;
    }
    int ans = sum[n] % 10007;
    printf("%d", ans);
    return 0;
}