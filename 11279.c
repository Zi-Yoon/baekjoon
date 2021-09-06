#include <stdio.h>
 
int h[100001],t=0;
int N;

void swap(int i, int j){
    int tmp=h[i];
    h[i]=h[j];
    h[j]=tmp;
}
 
void push(int x){
    h[++t]=x;
    for(int i=t; i>1; i/=2)
    {
        if(h[i]>h[i/2]) swap(i,i/2);
        else break;
    }
}
 
int pop(){
    int top=h[1];
    h[1]=h[t];
    h[t--]=0;   
    int i=1;
    while(i*2<=t){   
        if(h[i]>h[i*2] && h[i]>h[i*2+1]) break;
        else if (h[i*2]>h[i*2+1]){
            swap(i,i*2); i=i*2;
        } 
        else {
            swap(i,i*2+1); i=i*2+1;
        }
    }   
    return top;
}
 
int main(){
    int x;
    scanf("%d",&N);
    while(N--){     
        scanf("%d",&x);
        if(x==0) {
            if(t==0) printf("0\n");
            else printf("%d\n",pop());
        }
        else push(x);       
    }
    return 0;
}