#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
int arr[100][100];
int ans[100][100];
int visit[100];

// 깊이 우선 탐색 * Depth First Search
void dfs(int a)
{
    visit[a]++;
	if (visit[a] == 2)
		return ;
    for (int i = 0; i < n; i++)
    {
        if (arr[a][i] == 1 && visit[i] < 2)
            dfs(i);
	}
	return ;
}

int main() 
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);
    }
    memset(visit, 0, 100 * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        dfs(i);
        for (int j = 0; j < n; j++)
            ans[i][j] = visit[j];
		memset(visit, 0, 100 * sizeof(int));
	}

	for (int i = 0; i < n; i++)
	{
		if (ans[i][i] == 1)
			ans[i][i] = 0;
	}

    for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ans[i][j] == 2)
                ans[i][j] = 1;
			printf("%d ", ans[i][j]);
		}
        printf("\n");
    }
    return 0;
}
