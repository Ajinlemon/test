#include<stdio.h>
int main()

{

    int a;

    printf("输入一个整数\n");

    scanf("%d",&a);

    if(a == 0)
    
        {
            
             printf("0既不是奇数也不是偶数\n");
        
        }
        

        
     else if(a % 2 == 0)
        {
            
            printf("这个数是偶数\n");
        
        }
    

    else

        {

            printf("这个数是奇数\n");

        }

    return 0;

}
