#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;
    return (num1-num2);
}

int main() {
    int num, sum, ans;
    scanf("%d %d", &num, &sum);
    int card[num];
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &card[i]);
    }
    int max = 0;

    qsort(card, sizeof(card) / sizeof(int), sizeof(int), compare);

    for (int i = 0; i < num-2; i++)
    {
        for (int j = i+1; j < num-1; j++)
        {
            for (int k = j+1; k < num; k++)
            {
                ans = card[i] + card[j] + card[k];
                if (ans <= sum)
                {
                    if(max < ans)
                    {
                        max = ans;
                    }
                }
            }
        }
    }
    printf("%d", max);
    return 0;
}