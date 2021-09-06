#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    int factorial_1 = 1;
    int factorial_2 = 1;
    int factorial_3 = 1;

    for (int i = 1; i <= N; i++)
    {
        factorial_1 = factorial_1 * i;
    }
    for (int i = 1; i <= K; i++)
    {
        factorial_2 = factorial_2 * i;
    }
    for (int i = 1; i <= N-K; i++)
    {
        factorial_3 = factorial_3 * i;
    }

    int ans = factorial_1 / (factorial_2 * factorial_3);
    printf("%d", ans);
    return 0;
}