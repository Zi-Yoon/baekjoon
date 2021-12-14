#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m;
int arr[101][101];
int visit[101];
int cnt = -1;

// 깊이 우선 탐색 * Depth First Search
void dfs(int a)
{
	visit[a]++;
	if (visit[a] > 1)
		return;
	for (int i = 0; i < n; i++)
	{
		if (arr[a][i] == 1 && visit[i] < 2)
			dfs(i);
	}
	return;
}

int main() {
	int a, b;
    scanf("%d", &n); // 100 이하
    scanf("%d", &m); 
	memset(arr, 0, 101 * 101 * sizeof(int));
	for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
		a--;
		b--;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	arr[0][0] = 1;
	memset(visit, 0, 101 * sizeof(int));
	dfs(0);
	int i = 0;
	while (i < n)
	{
		if(visit[i] > 0)
			cnt++;
		i++;
	}
    printf("%d", cnt);
    return 0;
}