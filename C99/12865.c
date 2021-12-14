#include <stdio.h>
#include <stdlib.h>

int n, max;
int max_sum = 0;
int visit[100001][101];
int happy[100001];

typedef struct Backpack
{
    int weight;
    int value;
} bp;

bp backpack[101];

int compare(const void *a, const void *b)
{
    bp *temp1 = (bp *)a;
    bp *temp2 = (bp *)b;
    return (temp1->value - temp2->value);
}

int check()
{
    for (int i = 0; i <= max; i++) // weight
    {
        for (int j = 0; j < n; j++) // index
        {
            if(i >= backpack[j].weight)
            {
                int a = happy[i]; // 이전가치
                int b = happy[i - backpack[j].weight] + backpack[j].value; // 이전 가치 + 지금 가치
                if(a > b)
                {
                    happy[i] = a;
                    visit[i][i] = 1;
                }
                else if(visit[i]!=1)
                {
                    happy[i] = b;
                }
                
            }
        }
    }
    return happy[max];
}

int main() 
{
    scanf("%d %d", &n, &max);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &backpack[i].weight, &backpack[i].value);
    }
    qsort(backpack, n, sizeof(bp), compare);
    for (int i = 0; i <= max; i++) 
    {
        happy[i] = 0;
    }

    printf("%d", check(max));
    return 0;
}

