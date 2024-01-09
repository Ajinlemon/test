#include<stdio.h>

int main()


{ 
        int a,b,c;
        printf("输入三个整数");
        scanf("%d%d%d",&a,&b,&c);

        if(a>b&&a>c)
        printf("The biggest is %d\n",a);

        if(b>a&&b>c)
        printf("The biggest is %d\n",b);

        if(c>b&&c>a)
        printf("The biggest is %d\n",c);
        
        return 0;
}