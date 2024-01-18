#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
    FILE* pf;
    pf = fopen("./people","w+");  
    if(NULL  == pf)
    {
        perror("file open failed");
        return 1;
    }
	fprintf(pf, "may\njack\nrouse\ntom\n");
	rewind(pf); 
	char one[4][7];
	for(int i=0;i<4;i++)
	{
		fgets(one[i], sizeof(one[i]), pf);
		
    	}
   
	fclose(pf); 
	srand(time(NULL));   
	int indices[4] = {0, 1, 2, 3};
    	int n = 4;

    	for (int i = 0; i < 3; i++) {
        int randIndex = rand() % n;
        printf("%s", one[indices[randIndex]]);

        // 从数组中移除已经被选中的字符串
        indices[randIndex] = indices[n-1];
        n--;
    }
 

    return 0;
}

