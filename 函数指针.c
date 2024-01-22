#include<stdio.h>


int add(int a,int b)//定义一个普通函数
{
	
	

	return a + b;

}

int main()

{
	int sum;

	int (*add_p)(int,int) = add; //定义一个函数指针，并让它指向该函数
 	
	add_p(1,2); //调用所需的函数,如果需要计算两数之和就直接在main函数里面调用。
	sum  = add_p(1,2);
	
 	printf("sum =  %d\n",sum);

	return 0;
}
