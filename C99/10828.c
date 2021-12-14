#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, temp;
char order[6];

typedef struct stack
{
	int data;
	struct stack* link;
}stack;

stack *top;

int is_empty()
{
    if(top==NULL)
    {
        return 1;
    }
    return 0;
}

void push(int data)
{
    stack *newnode = (stack *)malloc(sizeof(stack));
    newnode->data = data;
    newnode->link = top;
    top = newnode;
}

int pop()
{
    if(!is_empty()) 
    {
        stack *temp = top;
        int data = temp->data;
        top = temp->link;
        free(temp);
        return data;
    }
    else
        return -1;
}

int peek()
{
    if(!is_empty()) 
    {
        return top->data;
    }
    else
    {
        return -1;
    }
}

int main() 
{
    scanf("%d", &n);
    int cnt = 0;
    stack *s = NULL;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &order);
        if(strcmp(order,"push") == 0)
        {
            scanf("%d\n", &temp);
            push(temp);
            cnt++;
        }
        else if(strcmp(order,"pop") == 0)
        {
            printf("%d\n", pop());
            cnt--;
            if(cnt<0){cnt=0;}
        }
        else if(strcmp(order,"empty") == 0)
        {
            printf("%d\n", is_empty());
        }
        else if(strcmp(order,"size") == 0)
        {
            printf("%d\n", cnt);
        }
        else if(strcmp(order,"top") == 0)
        {
            printf("%d\n", peek());
        }
    }
    return 0;
}