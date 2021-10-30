#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d", &n); // 100 이하
    scanf("%d", &m); 
    int temp[n+1][n+1];
    int pc[m][2];
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &pc[i][0], &pc[i][1]);
    }

    // reset
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            temp[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++)
    {
        if(pc[i][0] < pc[i][1])
        {
            temp[pc[i][0]][pc[i][1]] = 1;
        }
        else
        {
            temp[pc[i][1]][pc[i][0]] = 1;
        }
    }
    int cnt = 0;
    for (int i = 2; i <= n; i++)
    {
        if(temp[1][i]==1)
        {
            cnt++;
            for (int j = i+1; j <= n;j++)
            {
                if (temp[i][j] == 1)
                {
                    if(temp[1][j] !=1)
                    {
                        cnt++;
                    }
                }
            }
        }
    }
    printf("%d", cnt);
    return 0;
}