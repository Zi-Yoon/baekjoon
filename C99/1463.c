# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int arr[1000001];

int main()
{
    int x;
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 1;
    int cnt = 0;
    scanf("%d", &x);
    for (int i = 4; i <= x; i++)
    {
        int temp = arr[i-1] + 1;
        if(i%2==0)
        {
            if(arr[i/2] + 1 <temp)
            {
                temp = arr[i / 2] + 1;
            }
        }
        if(i%3==0)
        {
            if(arr[i/3] + 1 <temp)
            {
                temp = arr[i / 3] + 1;
            }
        }
        arr[i] = temp;
    }
    printf("%d",arr[x]);
    return 0;
}