#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int start;
    int end;
    int use;
} ttt;

int compare(const void *a, const void *b)
{
    ttt *temp1 = (ttt *)a;
    ttt *temp2 = (ttt *)b;
    if(temp1->end < temp2->end)
        return -1;
    else if (temp1->end > temp2->end)
        return 1;
    else
    {
        if(temp1->start < temp2->start)
            return -1;
        else if(temp1->start > temp2->start)
            return 1;
        else
            return 0;
    }
}


int main() {
    int n;
    scanf("%d", &n);
    ttt time[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &time[i].start, &time[i].end);
        time[i].use = time[i].start - time[i].end;
    }
    qsort(time, n, sizeof(ttt), compare);
    int ans = time[0].end;
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if(ans <= time[i].start)
        {
            cnt++;
            ans = time[i].end;
        }
    }
    printf("%d", cnt);
    return 0;
}
