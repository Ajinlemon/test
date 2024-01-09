#include<stdio.h>

int main()

{
    int* p1 = NULL;
    int* p2 = NULL;
    

    int a,b,c = 0;
    printf("输入两个数a b\n");

    scanf("%d%d",&a,&b);
        
    printf("输入的两个数是%d %d\n",a,b);    
        p1 = &a;
        p2 = &b;
        
        c = *p1;
        *p1 = *p2;
        *p2 = c;
        
        printf("a = %d\n",*p1);
        printf("b = %d\n",*p2);
        return 0;

}