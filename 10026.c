#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int RG_B_ans = 0, R_B_ans = 0;
int RG_B[102][102]; // 일반
int R_B[102][102];
int visit[102][102];
int visit_R[102][102];
char temp[1];

void find(int x, int y) // 좌표, 찾을 색깔
{
    visit[x][y] = 1;
    int temp_RGB = RG_B[x][y]; // 현재 색깔
    if (temp_RGB == 0)
    {
        return;
    }
    if(RG_B[x+1][y] == temp_RGB && visit[x+1][y] == 0)
    {
        find(x+1, y);
    }
    if(RG_B[x][y+1] == temp_RGB && visit[x][y+1] == 0)
    {
        find(x, y+1);
    }
    if(RG_B[x-1][y] == temp_RGB && visit[x-1][y] == 0)
    {
        find(x-1, y);
    }
    if(RG_B[x][y-1] == temp_RGB && visit[x][y-1] == 0)
    {
        find(x, y-1);
    }

    return;
}

void find_R(int x, int y) // 좌표, 찾을 색깔
{
    visit[x][y] = 1;
    int temp_RGB = R_B[x][y]; // 현재 색깔
    if (temp_RGB == 0)
    {
        return;
    }
    if(R_B[x+1][y] == temp_RGB && visit[x+1][y] == 0)
    {
        find_R(x+1, y);
    }
    if(R_B[x][y+1] == temp_RGB && visit[x][y+1] == 0)
    {
        find_R(x, y+1);
    }
    if(R_B[x-1][y] == temp_RGB && visit[x-1][y] == 0)
    {
        find_R(x-1, y);
    }
    if(R_B[x][y-1] == temp_RGB && visit[x][y-1] == 0)
    {
        find_R(x, y-1);
    }
    return;
}

int main() 
{
    scanf("%d\n", &n);
    memset(RG_B, 0, sizeof(RG_B));
    memset(R_B, 0, sizeof(R_B));
    memset(visit, 0, sizeof(visit));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%c", temp);
            if(temp[0] == '\n')
            {
                j--;
                continue;
            }
            if(temp[0] == 'R')
            {
                RG_B[i][j] = 1;
                R_B[i][j] = 1;
            }
            else if(temp[0] == 'G')
            {
                RG_B[i][j] = 3;
                R_B[i][j] = 1;
            }
            else if(temp[0] == 'B')
            {
                RG_B[i][j] = 2;
                R_B[i][j] = 2;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(visit[i][j] == 0) 
            {
                find(i, j);
                RG_B_ans++;
            }
        }
    }

    memset(visit, 0, sizeof(visit));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(visit[i][j] == 0) 
            {
                find_R(i, j);
                R_B_ans++;
            }
        }
    }

    printf("%d %d", RG_B_ans, R_B_ans);
    return 0;
}

