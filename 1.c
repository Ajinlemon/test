#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a;
  	system("stty -echo"); // 关闭回显
//	system("stty echo"); // 打开回显

	scanf("%d",&a);

	printf("输入的数为%d\n",a);
	return 0;

}
