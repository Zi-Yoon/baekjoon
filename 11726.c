#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    long long sum[1001]={0,1,2,3,};
    for (int i = 4; i < 1001; i++)
    {
        sum[i] = (sum[i - 1] + sum[i - 2]) % 10007;
    }
    int ans = sum[n] % 10007;
    printf("%d", ans);
    return 0;
}