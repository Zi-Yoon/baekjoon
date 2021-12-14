#include <stdio.h>
#include <stdlib.h>

int main() {
    long long P[101]={ 0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9,};
    int n, a;
    scanf("%d", &n);
    for (int i = 10; i < 101; i++)
    {
        P[i] = P[i - 5] + P[i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        printf("%lld\n", P[a]);
    }
    return 0;
}