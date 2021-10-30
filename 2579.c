#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int arrsum[100];
int add = 0;
int down_1_a(int arr[], int cnt, int sum, int one);
int down_2_a(int arr[], int cnt, int sum);
int down_2_b(int arr[], int cnt, int sum);

int main() {
    int n;
    scanf("%d", &n);
    int stair[300];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &stair[i]);
    }

    down_2_a(stair, n, 0); // 시작이 2칸
    down_1_a(stair, n, 0, 1); // 시작이 1칸

    int max = 0;
    for (int i = 0; i < 100; i++)
    {
        if(arrsum[i] > max)
        {
            max = arrsum[i];
        }
    }
    printf("%d", max);
    return 0;
}

int down_1_a(int arr[], int cnt, int sum, int one)
{
    sum += arr[cnt];
    cnt--;
    one++;
    if (cnt == 1)
    {
        return down_2_a(arr, cnt, sum);
    }
    else if (cnt ==0)
    {
        return down_1_a(arr, cnt, sum, 2);
    }
    else if (cnt == -1)
    {
        add = add + 1;
        *(arrsum + add) = sum;
        return *(arrsum+add);
    }
    down_2_b(arr, cnt, sum);
    return down_2_a(arr, cnt, sum);
}

int down_2_a(int arr[], int cnt, int sum)
{
    sum += arr[cnt];
    cnt--;
    cnt--;
    

    if (cnt == 1)
    {
        return down_2_b(arr, cnt, sum);
    }
    else if (cnt == 0)
    {
        return down_1_a(arr, cnt, sum, 1);
    }
    else if (cnt == -1)
    {
        add = add + 1;
        *(arrsum + add) = sum;
        return *(arrsum+add);
    }
    down_2_b(arr, cnt, sum);
    return down_1_a(arr, cnt, sum, 1);
}

int down_2_b(int arr[], int cnt, int sum)
{
    sum += arr[cnt];
    cnt--;
    cnt--;
    
    if (cnt == 1)
    {
        return down_2_b(arr, cnt, sum);
    }
    else if (cnt ==0)
    {
        return down_1_a(arr, cnt, sum, 1);
    }
    else if (cnt == -1)
    {
        add = add + 1;
        *(arrsum + add) = sum;
        return *(arrsum+add);
    }
    down_1_a(arr, cnt, sum, 1);
    down_2_a(arr, cnt, sum);
    return down_2_b(arr, cnt, sum);
}