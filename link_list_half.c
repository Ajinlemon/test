#include<stdio.h>
#include<stdlib.h>

//利用C语言来实现链表结构
#include<stdio.h>
//定义链表的样式
typedef int elem_type; //element 数据元素

typedef struct node
{
	elem_type data;  //数据域，存放数据元素
	
	struct node* next; // 指针域（指向后继节点）

}node, *list; //*list 代表这个结构体的指针


//创建一个空链表
//第一种方法，头结点只用来做头，不存放数据域
list create(void)
{

	node * p = malloc(sizeof(node));
	if(NULL == p)
{
	perror("malloc error");
	return NULL;
}
	p->next =NULL;
	
	return p;
	
}

//插入新节点（头插） 时间复杂度为O(1)
void push_front(list l,elem_type data)//目标链表，插入的数据
{
	//创建一个新节点
	node* p = malloc(sizeof(node));
	if(NULL==p)
	{
		perror("malloc error");
		return;
	}

	p->data = data;
	//将新节点插入到链表中，原来第一个节点变为该节点的后继，该节点成为第一个节点
	p->next = l->next;
	l->next = p;	

}

//插入新节点（尾插）
void push_back(list l,elem_type data)
{
	node*p = malloc(sizeof(node));
	if(NULL == p)
	{
		perror("malloc error");
		return;
	}
	p->data = data;
	//遍历链表找到尾结点
	node* q = l;
	while(q->next != NULL )	
		q = q->next;
		
	q->next = p;		
	
/*	while(1)
	{	
	 p->next = *(p->next)->next;
		if(NULL == *(p->next)->next)
		{	
	
		*(p->next)->next = p;
		return;
		}
	
	}

	p->next == NULL;	
	
	
	return;

	*/
}

// 插入一个新节点（中插）
//pos 指向的节点后面插入一个新节点
void insert(node *pos,elem_type data)
{
	node*p = malloc(sizeof(node));
        if(NULL == p)
         {
                  perror("malloc error");
                  return;
         }

	p->data = data;
	p->next = pos->next;
	pos->next = p;
			
}
//从链表中删除一个节点(根据节点指针删除)，时间复杂度为O(1),空间复杂度为O(1)
//删除pos指向节点的后继
void erase(node* pos)
{	//先用另一个指针去记录一下要释放那个数据的地址
	node* p = pos->next;				
	//再将链表缝合起来
	pos->next = pos->next->next;
	//最后释放要释放的那边空间
	free(p);
}

//根据节点数据的值来删除节点
int remover(list l,elem_type data)
{
	node* p = l;
	while(p->next!=NULL && p->next->data != data)
	{
		p = p->next;
	}		
		
	if(NULL == p->next)return 0;	
	
	erase(p);
	return 0;
}

//修改链表中某个节点的数据域
//修改链表中数据域为old_value的第一个节点的值为new_value
int update(list l,elem_type old_value,elem_type new_value)
{
	node* p = l->next;
	while(p!=NULL)
	{

	if(p->data == old_value)
		{
		p->data = new_value;
		return 1;

		}


	p = p->next;

	}

	return 1;
}

//在链表中查找某个节点
elem_type* find(list l,elem_type data)
{
	l =l->next;
	while(l !=NULL)
	{
		if(l->data == data) return &(l->data);	
	
	

		l = l->next; 
	

	}	

	return NULL;	

}





//遍历节点
//visit为访问函数，用它实现对每个节点的具体访问操作
void traverse(list l,int(*visit)(elem_type*))
{
	l = l->next;
	
	while(l != NULL)
	{	//如果某次调用访问函数返回值为0，就停止继续遍历链表
		if(!visit(&(l->data)))break;
	
		l = l->next;
	}	

}

int show_data(elem_type* p)
{
	printf("%d",*p);
	return 1;
	
}

int save_data(elem_type* p)
{
	static int cnt = 0;
	cnt++;
	if(cnt > 3) 
	{
		cnt = 3;
		return 0;
	}	

}




int main()

{
	list l1;
	l1 = create();
	push_back(l1,5);	
	push_front(l1,1);
	push_back(l1,3);
	push_front(l1,4);
	insert(l1,2);	
	insert(l1,6);
	traverse(l1,show_data);

	erase(l1);
	erase(l1);
	
	int n;
	printf("输入一个想要删除的数据");
	scanf("%d",&n);
	if(!remover(l1,n))
	{
	
	printf("success");
	
	}
	else
	{
	
	printf("no such file");	
	
	}

	update(l1,5,9);
	update(l1,12,15);


	traverse(l1,show_data);

	printf("\n");


	return 0;
}








