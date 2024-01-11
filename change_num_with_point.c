#include<stdio.h>
void change(float* a,float* b);
int main()

{       float a,b;

        printf("输入两个浮点数\n");

        scanf("%f %f",&a,&b);
        printf("a=%f,b=%f\n",a,b);    
        change(&a,&b);
        printf("a=%f,b=%f\n",a,b);


        return 0;
}
void change(float* a,float* b)
{           
	float c = *a;
        *a = *b;
        *b = c;


}

