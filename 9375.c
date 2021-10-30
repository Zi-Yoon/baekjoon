#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[21];
    char wear[21];
} cl;

int compare(const void *a, const void *b)
{
    cl *temp1 = (cl *)a;
    cl *temp2 = (cl *)b;
    return strcmp(temp1->wear, temp2->wear);
}

int main() {
    int test_case, clothes;
    int cnt[30];
    int n = 0;
    scanf("%d", &test_case);
    while(n < test_case)
    {
        for (int i = 0; i < 30; i++){cnt[i] = 1;}
        int ans = 1;
        scanf("%d", &clothes);
        cl fashion[clothes];
        for (int i = 0; i < clothes; i++)
        {
            scanf("%s %s", &fashion[i].name, &fashion[i].wear);
        }
        qsort(fashion, clothes, sizeof(cl), compare);

        for (int i = 0; i < clothes;)
        {
            cnt[i]++;
            int k = 1;
            if(i+k >= clothes)
            {
                break;
            }
            while(strcmp(fashion[i].wear, fashion[i+k].wear)==0)
            {
                cnt[i]++;
                k++;
            }
            i += k;
        }
        for (int i = 0; i < 30; i++)
        {
            ans = ans * cnt[i];
        }
        printf("%d\n", ans-1);
        n++;
    }
    return 0;
}
    