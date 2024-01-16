#include<stdio.h>
#include<time.h>




int main()
{
	
	time_t t;
	
	time(&t);

	struct tm* pt = localtime(&t);
	char* weekday[100]={"日","一","二","三","四","五","六"};

	printf("%d年%d 月%d日%02d:%02d:%02d 星期%s\n",pt->tm_year + 1900,pt->tm_mon+ 1,pt->tm_mday,pt->tm_hour,pt->tm_min,pt->tm_sec,weekday[pt->tm_wday]);

	return 0;

}














