#include<stdio.h>
#include<stdlib.h>

int main()
{
        int i;
        printf("输入三个数字\n");
        system("stty -echo"); // 关闭回显
        
        scanf("%d",&i);

        printf("这三个数字为%d\n",i);
        system("stty echo"); // 打开回显
        return 0;
}