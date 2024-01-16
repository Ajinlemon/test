#include<stdio.h>
#include<stdlib.h>
struct s//定义一个s类型结构体
{

	int ID;

};
struct p//定义一个p类型的结构体
{
	struct s s3;//p类型结构体里面嵌套了一个名字为s3的s型结构体
	struct s* ps;//p类型结构体里面嵌套一个指向s型结构体的指针ps

};
int main()
{
	struct p p1;
	p1.ps = malloc(sizeof(struct s));//如果要用指向运算符就得声明指针并分配存放空间
	p1.s3.ID = 12;
	p1.ps->ID = 12;


	free(p1.s3);//用完后记得释放空间
	
	return 0;
}
