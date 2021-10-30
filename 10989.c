#include <stdio.h>
#include <stdlib.h>

int main(){
    int N;
    scanf("%d", &N);
    int numArr[10001];
    int temp;
    for (int i = 1; i < 10001; i++)
    {
        numArr[i]=0;
    }

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &temp);
        numArr[temp]++;
    }
 
    for (int i = 1; i < 10001; i++)
    {
        if (numArr[i]==0)
        {
            continue;
        }
        else
        {
            for (int j = 0; j < numArr[i]; j++)
            {
                printf("%d\n", i);
            }  
        }
    }
    return 0;
}