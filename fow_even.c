#include<stdio.h>
#define CNT_ALL  100
void even (int cnt)

{

    for (cnt = 1;cnt<CNT_ALL;cnt++)
    {
        
        if (cnt % 2 == 0)
        
        {
        
            printf("在这CNT_ALL数内,偶数是%d\n",cnt);
        
        }
        


    }
    




}