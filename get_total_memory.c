#include<stdio.h>
int get_memory_size(char* ms);

int main()
{
	char mem_size[100];
	if(get_memory_size(mem_size))
	{
		fprintf(stderr,"fails\n");

	}
	else
	{
		fprintf(stdout,"机器内存为%s\n",mem_size);

	}	


	return 0;
}

int get_memory_size(char* ms)
{
	FILE*fp = 0;
	char name[50],num[50],unit[10];
	
	fp = fopen("/proc/meminfo","r");
		if(0 ==fp)return 1;
	
	fscanf(fp,"%s%s%s",name,num,unit);
		
	fclose(fp);

	sprintf(ms,"%s%s",num,unit);	
	return 0;
}
