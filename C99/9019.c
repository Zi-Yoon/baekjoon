#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10000000

int t, front = -1, rear = -1;
int queue[MAX];
int from[10001];
int check[10001];
char ans[10001];

void push(int a)
{
	queue[++rear] = a;
}
void pop()
{
	front++;
}
int empty()
{
    if(front == rear) return 1;
    else return 0;
}
int frontt()
{
	return queue[front + 1];
}

// DSLR
int D(int a)
{
	if(2 * a > 9999) return (2 * a) % 10000; 
	else return (2 * a);
}
int S(int a)
{
	if(a - 1 < 0) return 9999;
	else return a - 1;
}
int L(int a)
{
	return (a % 1000) * 10 + (a / 1000);
}
int R(int a)
{
	return (a % 10) * 1000 + (a / 10);
}

void print(int n, int m) 
{  
    if (n == m) return;
    print(n, from[m]);
    printf("%c", ans[m]);
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        int a, b;
        int temp_d, temp_s, temp_l, temp_r;
        rear = -1;
        front = -1;
        scanf("%d %d", &a, &b);
        memset(check,0,sizeof(check));
        memset(from,0,sizeof(from));
		memset(ans,0,sizeof(ans));
		from[a] = -1;
		check[a] = 1;
		push(a);
        while(!empty()){
			int k = frontt();
			pop();
			if(!check[D(k)])
            {
                temp_d = D(k);
                check[temp_d] = 1;
				push(temp_d);
				from[temp_d] = k;
				ans[temp_d] = 'D';
			}
			if(!check[S(k)])
            {
                temp_s = S(k);
                check[temp_s] = 1;
				push(temp_s);
				from[temp_s] = k;
				ans[temp_s] = 'S';
			}
			if(!check[L(k)])
            {
                temp_l = L(k);
                check[temp_l] = 1;
				push(temp_l);
				from[temp_l] = k;
				ans[temp_l] = 'L';
			} 
			if(!check[R(k)])
            {
                temp_r = R(k);
                check[temp_r]=1;
				push(temp_r);
				from[temp_r]=k;
				ans[temp_r] = 'R';
			} 
            if(check[b]==1)
            {
                break;
            }
        }
        print(a,b);
        printf("\n");
    }
    return 0;
}
    