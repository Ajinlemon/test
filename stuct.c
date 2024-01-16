#include<stdio.h>

#define N 5

//表示一个学生的结构体
struct student
{
	int sno;
	char name[20];
	char sex;	//0 表示女 1 表示男
	float sight;
	char phone[12];


};


int main()
{
	struct student s;	 //单个机构提变量 
	struct student stus[N];  //结构体数组
	int i;
	
	for(i = 0;i<N;i++)
{		
	
		printf("\n请按照提示依次输入第%d学生的各项信息\n",i + 1);
		printf("学号");
		scanf("%d",&s.sno);
		printf("姓名");
		scanf("%s",s.name);//name这个类型是char类型的数组，数组首元素就是指针，所以前面不用加&s
		getchar();			
		printf("性别( 0-女),(1-男)");
		scanf("%c",&s.sex);
		printf("视力");
		scanf("%f",&s.sight);
		printf("手机号");
		scanf("%s",s.phone);
		
		stus[i] = s;//将结构体里面的s都换成i 只有结构体能这样做！！！！！！！			
			
}	
     	return 0;
}
