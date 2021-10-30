#include <stdio.h>
#include <stdlib.h>
int n, m;
int maze[100][100];
int check[100][100] = {0,};

typedef struct{
    int x;
    int y;
    int cnt;
} node;

node que[10000];

int main() 
{
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            maze[i][j] = 0;
            check[i][j] = 0;
        }
    }
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &maze[i][j]);
        }
    }

    
    find_road(0, 0);
    printf("%d", ans);
    return 0;
}
