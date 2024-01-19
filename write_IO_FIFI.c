#include<stdio.h>
int main()
{
	FILE* fp = fopen("./yang","r");	
	if(NULL == fp)
	{
	perror("faile");
	return 1;
	}
	int f;
	fseek(fp,7,SEEK_SET);
	
	fread(&f,sizeof(int),1,fp);

	printf("%d\n",f);

	return 0;
}
