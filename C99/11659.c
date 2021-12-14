#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, i, j;
    scanf("%d %d", &n, &m);
    int num[n];
    int num_i, num_j;
    int ans[m+1];

    for (int k = 0; k < n; k++)
    {
        scanf("%d", &num[k]);
        ans[k + 1] = ans[k] + num[k];
    }

    for (int k = 0; k < m; k++)
    {
        scanf("%d %d", &num_i, &num_j);
        printf("%d\n", ans[num_j]-ans[num_i-1]);
    }
    
    return 0;
}
