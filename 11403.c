#include <stdio.h>
#include <stdlib.h>

int n;
int arr[100][100];
int ans[100][100];
int visit[100];

// 깊이 우선 탐색 * Depth First Search
void dfs(int a)
{
    visit[a]++;
    for (int i = 0; i < n; i++)
    {
        if(arr[a][i]==1 && visit[i]!=1)
        {
            dfs(i);
        }
    }
}

int main() 
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        visit[i]=0;
    }

    for (int i = 0; i < n; i++)
    {
        dfs(i);
        for (int j = 0; j < n; j++)
        {
            if(i==j && visit[j] !=2)
            {
                ans[i][j] = 0;
                visit[j] = 0;
                continue;
            }
            ans[i][j] = visit[j];
            visit[j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ans[i][j] == 2)
			{
                ans[i][j]--;
            }
			printf("%d ", ans[i][j]);
		}
        printf("\n");
    }
    return 0;
}
