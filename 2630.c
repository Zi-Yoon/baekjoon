#include <stdio.h>
#include <stdlib.h>

int blue = 0;
int white = 0;

// temp box
int temp_box[64][64];

int check(int n);
void put(int n, int box[n][n], int num);
void divide(int n, int box[n][n]);

int main() {
    int n;
    scanf("%d", &n);
    int box[n][n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &box[i][j]);
            sum += box[i][j];
        }
    }

    if(sum == n*n)
    {
        blue++;
    }
    else if(sum == 0)
    {
        white++;
    }
    if(sum == n*n || sum == 0)
    {
        printf("%d\n", white);
        printf("%d", blue);
        return 0;
    }

    divide(n, box);

    printf("%d\n", white);
    printf("%d", blue);
    return 0;
}

void put(int n, int box[n][n], int num)
{
    int real = n / 2;
    int x = 0;
    int y = 0;
    switch(num)
    {
        case 1:
            x = 0;
            y = 0;
            break;
        case 2:
            x = real;
            y = 0;
            break;
        case 3:
            x = 0;
            y = real;
            break;
        case 4:
            x = real;
            y = real;
            break;
    }
    for (int i = x; i < x+real; i++)
    {
        for (int j = y; j < y+real; j++)
        {
            temp_box[i][j] = box[i][j]; 
        }
    }
    if(real==1)
    {
        check(1);
        return;
    }
    if(check(real)==0)
    {
        divide(real, temp_box);
    }
}

void divide(int n, int box[n][n])
{
    put(n, box, 1);
    put(n, box, 2);
    put(n, box, 3);
    put(n, box, 4);
    return;
}

int check(int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(temp_box[i][j]==1)
            {
                cnt++;
            }
        }
    }
    if (cnt == n*n)
    {
        blue++;
        return 1;
    }
    else if (cnt == 0)
    {
        white++;
        return 1;
    }
    else
    {
        return 0;
    }
}