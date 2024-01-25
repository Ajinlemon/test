#include <stdio.h>
#include <stdlib.h>


typedef struct person
{
	int num;
	struct person* next;

} person;


int main()
{
	int i, cnt = 41;
	person* head = NULL, *p = NULL, *q = NULL;

	head = malloc(sizeof(person));
	head->num = 1;
	head->next = NULL;

	q = head;

	for(i = 2; i <= 3; i++)
	{
		p = malloc(sizeof(person));
		p->num = i;
		p->next = NULL;

		q->next = p;
		q = p;
	}

	p->next = head;

	i = 1;
	q = head;

	while(cnt > 2)
	{
		i++;	
		head = q->next;

		if(i % 3 == 0)
		{
			q->next = head->next;	
			free(head);
			
			cnt--;

			continue;	
		}
		
		q = head;	
	}

	printf("%d %d\n", q->num, q->next->num);

	return 0;
}
