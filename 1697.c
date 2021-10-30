#include <stdio.h>
#include <stdlib.h>

int n, k, now, cnt = 0, last = 0, first = 0;
int visit[100001] = {0};

typedef struct{
    int front;
    int rear;
} Queue;

void init_queue(Queue *q){
    q->front=q->rear=-1;
}

int main()
{
    scanf("%d %d", &n, &k); // n=현재위치 k=목표위치


}