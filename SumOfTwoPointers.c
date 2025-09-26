#include<stdio.h>
int main(){
    int a,b,c,*p,*q;
    p = &a;
    q = &b;
    c = *p + *q;
    printf("Enter the two numbers :");
    scanf("%d %d",p,q);
    c = *p + *q;
    printf("The sum of two %d and %d is %d ",*p,*q,c);
    return 0;
}