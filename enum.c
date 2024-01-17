#include<stdio.h>
//声明枚举类型 sex
enum sex
{
	male  ,
	female = 6,
	unknow //此时这个值为7，会在前面的元素后面+1
}; //大括号里的是枚举元素，该枚举类型数据的取值只能是这些枚举元素
// tips:注意符号问题
int main()

{
	//使用枚举类型定义变量s1
/*	enum sex s1 = male;
	s1  = female;
	if(s1 == male)
	{	
		printf("boy\n");
	}
	else
	{
	printf("girl\n");
	}
	printf("%d\n",(int)s1);
*/
	printf("%d %d %d\n",male,female,unknow);
	return 0;
}
