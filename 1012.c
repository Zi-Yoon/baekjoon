#include <stdio.h>
#include <stdlib.h>

//DFS
int field[52][52];
int visit[52][52];
int t, x, y, k;

int reset()
{
    for (int i = 0; i < 51; i++)
    {
        for (int j = 0; j < 51; j++)
        {
            field[i][j] = 0;
            visit[i][j] = 0;
        }
    }
}

int DFS(int hx, int hy) // 위 오 아래 왼
{
    if(field[hx][hy]==1 && visit[hx][hy]==0)
    {
        visit[hx][hy] = 1;
        field[hx][hy] = 0;
        if(field[hx-1][hy]==1 && visit[hx-1][hy]==0){DFS(hx - 1, hy);}
        if(field[hx][hy+1]==1 && visit[hx][hy+1]==0){DFS(hx, hy + 1);}
        if(field[hx+1][hy]==1 && visit[hx+1][hy]==0){DFS(hx + 1, hy);}
        if(field[hx][hy-1]==1 && visit[hx][hy-1]==0){DFS(hx, hy - 1);}
        return 1;
    }
    return 0;
}

int main() 
{
    scanf("%d", &t);
    int a, b, cnt;
    int min_a = 50, min_b = 50;
    for (int i = 0; i < t; i++)
    {
        cnt = 0;
        scanf("%d %d %d", &x, &y, &k);
        for (int i = 0; i < k; i++)
        {
            scanf("%d %d", &a, &b);
            field[a][b] = 1;
        }
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                cnt += DFS(i, j);
            }
        }
        printf("%d\n", cnt);
        reset();
    }
    return 0;
}