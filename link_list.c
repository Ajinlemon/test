#include <stdio.h>
#include <stdlib.h>


typedef int elem_type;
/*
typedef struct goods
{
	int gid;
	char name[50];
	float price;
	//...

} elem_type;
*/

typedef struct node
{
	 elem_type data;     // 数据域，存放数据元素

	 struct node* next;  // 指针域（指向后继节点） 

} node;


typedef struct
{
	node* head;  // 链表头节点指针
	node* tail;  // 链表尾节点指针
	int size;    // 链表长度
} *list;


// 创建一个空链表（只有一个头结点）
list create(void)
{
	node* p = malloc(sizeof(node));

	if(NULL == p)
	{
		perror("malloc error");
		return NULL;
	}

	p->next = NULL;

	list l = NULL;

	l = malloc(sizeof(*l));

	if(NULL == l)
	{
		perror("malloc error");
		return NULL;
	}

	l->head = l->tail = p;
	l->size = 0;

	return l;
}


// 销毁链表（删除所有节点）
void destroy(list l)
{
	node* p;

	// 释放链表 l 的所有节点
	while(l->head != NULL)
	{
		p = l->head->next;
		free(l->head);
		l->head = p;
	}
	
	// 释放链表信息结构体
	free(l);
}


// 清空链表（除了头节点，删除其他所有节点，因为头节点没有存放数据元素）
void clear(list l)
{
	node* p, *q;

	// 将头节点的 next 指针域设置为 NULL
	p = l->head->next;
	l->head->next = NULL;

	// 删除除头节点之外的所有其他节点
	while(p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}

	l->tail = l->head;
	l->size = 0;
}


// 判空，时间复杂度为 O(1)
int empty(list l)
{
	return !(l->size);
}


// 求长度，时间复杂度为 O(1)
int size(list l)
{
	return l->size;
}


// 插入新节点（头插），时间复杂度为 O(1)，空间复杂度为 O(1)
void push_front(list l, elem_type data)
{
	// 创建一个新节点
	node* p = malloc(sizeof(node));

	if(NULL == p)
	{
		perror("malloc error");
		return;
	}

	p->data = data;

	// 将新节点插入到链表中，原来的第一个节点变为该节点的后继，该节点成为第一个节点
	p->next = l->head->next;
	l->head->next = p;

	if(l->size == 0) l->tail = p;

	l->size++;
}


// 插入新节点（尾插），时间复杂度为 O(1)，空间复杂度为 O(1)
void push_back(list l, elem_type data)
{
	// 创建一个新节点
	node* p = malloc(sizeof(node));

	if(NULL == p)
	{
		perror("malloc error");
		return;
	}

	p->data = data;
	
	// 将新节点插入到链表中，它将成为尾节点，而原来的尾节点的后继为该节点
	p->next = NULL;
	
	l->tail->next = p;
	l->tail = p;
	l->size++;
}


// 插入一个新节点（中插，即在任意位置插入），时间复杂度为 O(1)，空间复杂度为 O(1)
// 在 pos 指向的节点后面插入一个新节点
void insert(list l, node* pos, elem_type data)
{
	// 创建一个新节点
	node* p = malloc(sizeof(node));

	if(NULL == p)
	{
		perror("malloc error");
		return;
	}

	p->data = data;

	// 将新节点插入到 pos 指向的节点之后
	p->next = pos->next;
	pos->next = p;

	if(p->next == NULL) l->tail = p;
	l->size++;
}


// 从链表中删除一个节点（根据节点指针删除），时间复杂度为 O(1)，空间复杂度为 O(1)
// 删除 pos 指向节点的后继
void erase(list l, node* pos)
{
	node* p = pos->next;

	pos->next = p->next;
	free(p);

	if(pos->next == NULL) l->tail = pos;

	l->size--;
}


// 从链表中删除一个节点（根据节点数据域删除），时间复杂度为 O(n)，空间复杂度为 O(1)
// 从链表 l 中删除数据域的值为 data 的第一个节点
int remove2(list l, elem_type data)
{
	node* p = l->head, *q;

	// 遍历链表，找到要删除节点的前驱节点
	while(p->next != NULL && p->next->data != data)
		p = p->next;

	// 如果不存在目标节点
	if(NULL == p->next) return 0;

	// 删除目标节点（注意不要破坏链表的结构）
	q = p->next;
	p->next = q->next;
	free(q);

	if(p->next == NULL) l->tail = p;

	l->size--;
	
	return 1;
}


// 修改链表中某个节点的数据域
// 将链表 l 中的数据域为 old_value 的第一个节点的数据域更新为 new_value
int update(list l, elem_type old_value, elem_type new_value)
{
	node* p = l->head->next;

	while(p != NULL)
	{
		if(p->data == old_value)
		{
			p->data = new_value;
			return 1;
		}

		p = p->next;
	}

	return 0;
}


// 随机访问某个数据元素（即根据数据元素的位置进行访问），时间复杂度为 O(n)
elem_type* at(list l, int pos)
{
        node* p = l->head->next;

	while(pos--) p = p->next;

	return &(p->data);
}


// 在链表中查找某个节点
elem_type* find(list l, elem_type data)
{
	node* p = l->head->next;

	while(p != NULL)
	{
		if(p->data == data) return &(p->data);

		p = p->next;
	}

	return NULL;
}


// 逆序
void reverse(list l)
{
	if(NULL == l->head->next) return;

	node* p = l->head->next->next, *q;

	l->head->next->next = NULL;  // 原来的第 1 个节点逆序处理后将成为尾节点，所以这里将它的 next 指针域设置为 NULL
	l->tail = l->head->next;

	// 从第 2 个节点开始依次插入到链表头节点之后
	while(p != NULL)
	{
		q = p->next;
		p->next = l->head->next;
		l->head->next = p;
		
		p = q;
	}
}


// 排序（升序）
void sort(list l)
{
	// 选择排序算法
	node* p, *q, *k;
	elem_type tmp;

	if(l->head->next == NULL) return;  // 如果链表为空，不用进行任何处理

	p = l->head->next;

	while(p->next != NULL)
	{
		k = p;
		q = p->next;

		while(q != NULL)
		{
			if(q->data < k->data) k = q;	

			q = q->next;
		}

		if(k != p)
		{
			// 交换数据域，没有交换指针域高效
			tmp = k->data;
			k->data = p->data;
			p->data = tmp;
		}

		p = p->next;
	}
}


// 遍历节点
// visit 为访问函数，用它实现对每个节点的具体访问操作
void traverse(list l, int(*visit)(elem_type*))
{
	node* p = l->head->next;

	while(p != NULL)
	{
		// 如果某次调用访问函数返回值为 0，就停止继续遍历链表
		if(!visit(&(p->data))) break;
		
		p = p->next;
	}
}



int show_data(elem_type* p)
{
	printf("%d ", *p);

	return 1;
}


int save_data(elem_type* p)
{
	static int cnt = 0;

	cnt++;

	if(cnt > 3)
		return 0;

	FILE* fp = fopen("data", "a");

	if(NULL == fp)
	{
		perror("fopen error");
	}
	else
	{
		fprintf(fp, "%d\n", *p);
		fclose(fp);
	}

	return 1;
}


int main()
{
	list l1;

	l1 = create();

	reverse(l1);

	push_back(l1, 5);
	push_front(l1, 1);

	printf("链表长度：%d\n", size(l1));

	clear(l1);

	if(empty(l1))
		printf("链表空空如也！\n");

	push_back(l1, 3);
	push_front(l1, 4);
	insert(l1, l1->head, 2);
	insert(l1, l1->tail, 6);

	// 将链表 l1 中的第 2 个数据赋值为 777
	*at(l1, 2) = 777;
	/*
	elem_type* p = at(l1, 2);
	*p = 777;
	*/

	if(!empty(l1))
		printf("链表非空！\n");

	printf("链表长度：%d\n", size(l1));

	traverse(l1, show_data);
	printf("\n");

	reverse(l1);

	traverse(l1, show_data);
	printf("\n");

	sort(l1);  // 升序

	traverse(l1, show_data);
	printf("\n");

	traverse(l1, save_data);

	erase(l1, l1->head);
	erase(l1, l1->head);

	remove2(l1, 3);


	int n;
	printf("请输入一个要删除的整数：");
	scanf("%d", &n);

	if(remove2(l1, n))
		printf("删除成功！\n");
	else
		printf("数据不存在，删除失败！\n");

	
	update(l1, 5, 9);
	update(l1, 8, 18);

	if(!find(l1, 8))
	{
		printf("8 不存在！\n");	
	}

	*find(l1, 6) = 666;

	traverse(l1, show_data);
	printf("\n");

	destroy(l1);
	
	return 0;
}
