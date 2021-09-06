#include <stdio.h>
#include <stdlib.h>

int n;
int num_m1 = 0, num_0 = 0, num_1 = 0;
int cnt_m1 = 0, cnt_0 = 0, cnt_1 = 0;
int dv(int arr[][n], int n, int x, int y);

int main() {
    scanf("%d", &n);
    int paper[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&paper[i][j]);
            switch(paper[i][j])
            {
                case(-1):
                    cnt_m1++;
                    break;
                case(0):
                    cnt_0++;
                    break;
                case(1):
                    cnt_1++;
                    break;
            }
        }
    }
    // 하나일때 체크
    if (cnt_m1 == n * n)
    {
        num_m1++;
    }
    else if(cnt_0 == n * n)
    {
        num_0++;
    }
    else if(cnt_1 == n * n)
    {
        num_1++;
    }
    else
    {
        dv(paper, n, 0, 0);
    }
    printf("%d\n", cnt_m1);
    printf("%d\n", cnt_0);
    printf("%d", cnt_1);
    return 0;
}

int dv(int arr[][n], int n, int x, int y)
{   
    cnt_m1 = 0;
    cnt_0 = 0;
    cnt_1 = 0;
    int t_size = n / 3;
    int t2_size = t_size * t_size;
    for (int i = x*3; i < t_size+x*3; i++)
    {
        for (int j = y*3; j < t_size+y*3; j++)
        {
            switch(arr[i][j])
            {
                case(-1):
                    cnt_m1++;
                    break;
                case(0):
                    cnt_0++;
                    break;
                case(1):
                    cnt_1++;
                    break;
            }
            if (cnt_m1 == t2_size)
            {
                num_m1++;
                return 0;
            }
            else if(cnt_0 == t2_size)
            {
                num_0++;
                return 0;
            }
            else if(cnt_1 == t2_size)
            {
                num_1++;
                return 0;
            }
        }
    }
    dv(arr, t_size, x+1, y);
    dv(arr, t_size, x+2, y);
    dv(arr, t_size, x+1, y+1);
    dv(arr, t_size, x+2, y+1);
    dv(arr, t_size, x+1, y+2);
    dv(arr, t_size, x+2, y+2);
}