#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n, r, c;
int cnt = 0;
int search(int size, int x, int y)
{
    if(x==c && y==r)
    {
        return 0;
    }
    if(size >= 1)
    {
        if(size + x > c && size + y > r)
        {
            int half = size / 2;
            if(half + x > c && half + y > r)
            {
                search(half, x, y);
            }
            else if(half + y > r)
            {
                cnt += half * half;
                search(half, x + half, y);
            }
            else if(half + x > c)
            {
                cnt += 2*(half * half);
                search(half, x, y + half);
            }
            else // if(size > c && size > r)
            {
                cnt += 3*(half * half);
                search(half, x + half, y+ half);
            }
        }
    }
    else
    {
        cnt++;
    }
}

int main() 
{
	scanf("%d %d %d", &n, &r, &c); 
    search(pow(2, n), 0, 0);
    printf("%d", cnt);
    return 0;
}
