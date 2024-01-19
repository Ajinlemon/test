#include<stdio.h>

int main()

{
	 const char* s = "测你妈 -12345678 3.1415a";//常量区定义字符串指针
	char str[30];
	int i;
	float f;
	char c;
	sscanf(s,"%s%d%f%c",str,&i,&f,&c);//从s这个字符串中，输入数据
	//fscanf(s,"%s",pt);//将s字符串输入到文件pt中	
	//scanf("%d",&i);//输入一个int型数据到i中
/*	printf("%s",str);
	printf("%d",i);
	printf("%g",f);
	printf("%c",c);
	printf("\n");
*/
	char str2[100];
	
	sprintf(str2,"%d",i);//将字符串转换为int数据并输出到str数组中 tips:双引号里面也可以直接构造想要的字符串

	//printf("%d",i);//将字符串输出到终端窗口	
	//fprintf(fp,"%d",i);//将字符串输出到文件中
	
	printf("%s\n",str2);	

	return 0;
}
