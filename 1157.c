#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int compare(const void *a, const void *b)
{
    return strcmp((char*)a, (char*)b);
}

int main() {
    char word[1000000];
    char count[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    scanf("%s", word);
    int len = strlen(word);
    int count_num[1000000] = {0,};
    for (int i = 0; i < len; i++)
    {
        word[i]=toupper(word[i]);
    }

    qsort(word, sizeof(word) / sizeof(char), sizeof(char), compare);
    int cnt = 0;

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if(word[i] == word[j])
            {
                count_num[i]++;
                i++;
            }
            else
            {
                break;
            }
        }
    }

    int max = 0;
    // find max
    for (int k = 0; k < len;k++)
    {
        if (count_num[k] > max)
        {
            max = count_num[k];
        }
    }

    // find max char
    for (int m = 0; m < len; m++)
    {
        if (count_num[m] == max)
        {
            cnt++;
        }
    }

    // last
    if (cnt >= 2)
    {
        printf("?");
        return 0;
    }
    else
    {
        for (int i = 0; i < len; i++)
        {
            if(count_num[i] == max)
            {
                printf("%c",word[i]);
                return 0;
            }
        }
    }
}
