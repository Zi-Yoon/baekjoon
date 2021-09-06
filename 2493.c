#include <stdio.h>
#include <stdlib.h>

int tower[500001];
int temp[500001];

int main() 
{
    int n;
    scanf("%d", &n);
    int max = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &tower[i]);
        if(tower[i]>max)
        {
            max = tower[i];
            printf("%d ", 0);
        }
        else
        {
            int j = i - 1;
            for (; tower[j] < tower[i]; j = temp[j]);
            if (tower[j] >= tower[i])
            {
                temp[i] = j;
                printf("%d ", j);
            }
        }
    }
    return 0;
}