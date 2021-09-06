#include <stdio.h>
#include <stdlib.h>

struct hotel{
    int x, y;
};

int main() {
    int t; // 시나리오 갯수
    scanf("%d", &t);
    int h[t]; // 층수
    int w[t]; // 방갯수
    int n[t]; // 손님수
    int ans[t]; // 정답
    for (int num = 0; num < t; num++)
    {
        h[num]=0;
        w[num]=0;
        n[num]=0;
        ans[num]=0;
    }

    for (int i = 0; i < t;i++){
        scanf("%d %d %d", &h[i], &w[i], &n[i]);
    }

    for (int num = 0; num < t; num++)
    {
        if(n[num] % h[num] == 0)
        {
            ans[num] = ((n[num] - 1) % h[num]) * 100 + (n[num] / h[num]) + 100;
        }
        else
        {
            ans[num] = (n[num] % h[num]) * 100 + (n[num] / h[num]) + 1;
        }
    }

    for (int i = 0; i < t; i++){
        printf("%d\n", ans[i]);
    }
    return 0;
}