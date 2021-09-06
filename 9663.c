#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int n, ans = 0, cnt = 0, Y = 0;
int tem_cnt = 0;
int chess[15][15];
int temp_temp[15][15];
int sum = 0;

// queen을 체스판에 놓는 함수
void put(int x, int y)
{
    cnt++;
    int a = abs(x - y);
    int b = x + y;
    // 수직 수평 제거
    for (int i = 0; i < n; i++)
    {
        temp_temp[i][y] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        temp_temp[x][i] = 1;
    }
    // 대각선 제거
    if(x >= y)
    {
        int j = 0;
        for (int i = a; i < n; i++)
        {
            temp_temp[i][j] = 1;
            j++;
        }
        j = b;
        for (int i = 0; i < b; i++)
        {
            temp_temp[i][j] = 1;
            j--;
        }
    }
    else
    {
        int j = 0;
        for (int i = a; i < n; i++)
        {
            temp_temp[j][i] = 1;
            j++;
        }
        j = b;
        for (int i = 0; i < b; i++)
        {
            temp_temp[j][i] = 1;
            j--;
        }
    }
}

int check()
{
    sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum += temp_temp[i][j];
        }
    }
    
    if (sum == n * n)
        return 1;
    else
        return 0;
}

void find(int x, int y)
{

    // 완성됬는지 확인
    while (tem_cnt < n)
    {
        if(temp_temp[x][tem_cnt] == 0)
        {
            put(x, tem_cnt);
            tem_cnt++;
            if(check() == 1 && cnt == n)
            {
                ans++;
                cnt = 0;
                return;
            }
            x++;
            find(x, y);
            return;
        }
        else if(tem_cnt == n-1)
        {
            Y++;
            cnt = 0;
            memset(temp_temp, 0, sizeof(temp_temp));
            find(0, Y);
            return;
        }
    }
    
    return;
}



int main() 
{
    scanf("%d", &n);
    memset(chess, 0, sizeof(chess));
    memset(temp_temp, 0, sizeof(temp_temp));

    find(0, 0);
    printf("%d", ans);
    return 0;
}
