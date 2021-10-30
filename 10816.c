#include <stdio.h>
#include <stdlib.h>

int n, m;

typedef struct open_card{
    int hand_arr;
    int index;
    int ans;
}oc;

typedef struct hand_card{
    int hand_arr;
    int ans;
}hc;

int compare(const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int compare_open(const void *a, const void *b)
{
    oc *temp1 = (oc *)a;
    oc *temp2 = (oc *)b;
    return temp1->hand_arr - temp2->hand_arr;
}

int compare_open_index(const void *a, const void *b)
{
    oc *temp1 = (oc *)a;
    oc *temp2 = (oc *)b;
    return temp1->index - temp2->index;
}

int main(){
    scanf("%d", &n);
    oc card[n];
    oc *pos;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &card[i].hand_arr);
        card[i].index = i;
        card[i].ans = 0;
    }
    qsort(card, n, sizeof(oc), compare_open); // 퀵소트

    int k = 0;
    int j = 1;
    int cnt = 1;
    for (int i = 0; i < n - j;)
    {
        j = 1;
        cnt = 1;
        while(card[i].hand_arr == card[i+j].hand_arr)
        {
            card[i + j].hand_arr = 10000001 + i;
            j++;
            cnt++;
        }
        card[i].ans = cnt;
        i += cnt;
    }

    qsort(card, n, sizeof(oc), compare_open); // 퀵소트

    scanf("%d", &m);
    hc hand[m];
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &hand[i].hand_arr);
        hand[i].ans = 0;
    }

    // 이진탐색
    for (int i = 0; i < m; i++)
    {
        pos = (oc *)bsearch(&hand[i].hand_arr, card->hand_arr, n, sizeof(oc), compare);
        if(pos!=NULL)
        {
            hand[i].ans = pos->ans;
        }
    }

    for (int i = 0; i < m; i++)
    {
        printf("%d ", hand[i].ans);
    }

    return 0;
}