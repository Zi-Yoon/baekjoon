#include <stdio.h>
#include <stdlib.h>

int n, m;
int answer = 1;
int visited[1001][1001];
int check[1001];

void ans(int num)
{
    for (int i = num+1; i <= n; i++)
    {
        if(visited[num][i]==1 && check[i]!=1)
        {
            check[i] = 1; 
        }
        else if(visited[num][i]==1 && check[i] ==1)
        {
            check[num] = 1;
        }
    }
    if(num+1 <= n)
    {
        ans(num + 1);
    }
    return;
}

int main() {
    scanf("%d %d", &n, &m);
    int temp1, temp2;
    // reset
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            visited[i][j] = 0;
        }
        visited[i][i] = 1;
        check[i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &temp1, &temp2);
        if(temp1>temp2)
        {
            visited[temp2][temp1] = 1;
        }
        else
        {
            visited[temp1][temp2] = 1;
        }
    }
    check[1] = 1;
    ans(1);
    for (int i = 1; i <= n; i++)
    {
        if(check[i]==0)
        {
            answer++;
        }
    }
    printf("%d", answer);
    return 0;
}
