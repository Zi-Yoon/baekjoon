#include <stdio.h>
#include <stdlib.h>

int main() {
    // a = 97 -> a = 97 - 96
    int M = 1234567891;
    int L;
    scanf("%d", &L);
    char eng[L+1];
    long long hash[L];
    scanf("%s", eng);

    long long A = 1;
    unsigned long long sum = 0;

    for (int i = 0; i < L; i++)
    {
        hash[i] = ((eng[i] - 96) * A) % M;
        sum += hash[i] % M;
        A = (A * 31) % M;
    }

    printf("%llu", sum);
    return 0;
}