#include<stdio.h>

struct person

{
	char i;
	int  c;
	double l;
	char j;

};

int main()

{

	struct person p1= {'b',1,1.11,'a'};
	printf("%ld\n",sizeof(p1));

/*	printf("%p\n",&p1);	
	printf("%p\n",&p1.i);
	printf("%p\n",&p1.c);
	printf("%p\n",&p1.j);
*/




	return 0;
}
