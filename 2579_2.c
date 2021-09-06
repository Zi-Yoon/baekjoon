#include <stdio.h>
#include <stdlib.h>

int max(int temp1, int temp2)
{
    if(temp1 > temp2)
    {
        return temp1;
    }
    else if(temp2 > temp1)
    {
        return temp2;
    }
    else
    {
        return temp1;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int stair[300];
    int temp[300]; // i까지의 최댓값을 저장
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &stair[i]);
    }
    temp[0] = stair[0];
    temp[1] = max(stair[0] + stair[1], stair[1]);
    temp[2] = max(stair[0] + stair[2], stair[1] + stair[2]);
    for (int i = 3; i < n; i++)
    {
        temp[i] = max(stair[i] + temp[i - 2], stair[i] + stair[i - 1] + temp[i - 3]);
    }
    printf("%d", temp[n - 1]);
}