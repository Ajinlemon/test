#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{	
	
	/* for(int i = 0;i<10;i++)
	{
		printf("abc\n");
		//fflush(stdout);//刷新标准输出缓冲区
		sleep(1);//休眠一秒钟
	}
	int i=3,j=5;
	printf("请输入一个整数");
	scanf("%d",&i);
	if(scanf("%d",&i)!=1)
	{
		//如果本次输入失败，就清空标准输入缓冲区，否则就会影响下面的输入操作.
		while(getchar()!='\n');//利用getchar一直调用缓冲区中的数据，直到getchar读到'\n'就停止
	}	
	printf("请再输入一个整数");
	scanf("%d",&j);
	printf("i=%d,j=%d\n",i,j);
	*/
	FILE* fp = NULL;
	fp = fopen("./yang","w");//这里绝对路径和相对路径都可以，而且这里./ 不用写，默认是从当前工作文件夹下面找。tips:如果文件不存在，就会创建一个文件,如果目标文件已存在，就会清空其已有数据。                 
	if(NULL == fp)
	{
		perror("打开文件夹失败");
		return 1;
	}
	//用putc输入一个字符，字符类型随意	
	fputc('a',fp);	
	fputc(51,fp);
	fputc(0x41,fp);
	//用puts输入一个字符串
	char name[]="what fuck\n";
	fputs(name,fp);
	//用fprintf输入数据
	int i= 1684234849;
	float f = -3.14;
	fprintf(fp,"\ndata is %d,%g\n",i,f);//在文件中显示这个字符串

	//使用fwrite输入数据
	fwrite(&i,sizeof(int),1,fp);//将内存中i存放的数据写入fp所指的文件中 fwrite(数据地址，大小，个数，写入的文件的指针)
	fwrite(&f,sizeof(float),1,fp);
	//写入一个栈区数组	
	int num[] = {5,3,4,1,2};
	fwrite(&num[0],sizeof(int),5,fp);

	//写入一个堆区数组	
	int* nums2 = malloc(5*sizeof(int));
	for(int i=0;i<5;i++)
		nums2[i] = i + 3;
	
	fwrite(nums2,sizeof(int),5,fp);
	free(nums2);
	
	fclose(fp);//关闭文件，tip 里面参数是指针。
	
	return 0 ;
}
