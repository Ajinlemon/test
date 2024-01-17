#include<stdio.h>
#include<string.h>
/*union person
{
	int pid;
	char sex;
//	double sight;
	short nums[6];//大小为12

};*/

struct teacher_info
{
	int tid;
	char name[20];
	char sex;
	char level;// 0 表示教授，1 -企业导师，2-兼职讲师，3-专职讲师
	union level_pro
	{

		char pro[40];
		char engineer[40];
		char teacher[40];
		

	}lp;

};

int main()
{
	struct teacher_info t1 = {1001,"张三",'0'},t2={1002,"李四",'1'};
	t1.level = 0;	
	strcpy(t1.lp.pro,"副");
	
	t2.level = 1;
	strcpy(t2.lp.engineer,"中级");
	
	printf("张三是%s教授\n",t1.lp.pro);			



/*	union person p1;
	printf("%ld\n",sizeof(p1));//12 因为对齐系数为8，最大数据类型是int型，所以最后的空间是int型的整数倍，而里面最宽的数据是12,12是4的整数倍所以就输出12
*/
	return 0 ;
}
