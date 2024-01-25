#include <stdio.h>
#include <stdlib.h>


typedef int elem_type;


typedef struct 
{
	elem_type* data;  // 首元素的指针
	int size;         // 长度（即当前数据元素的个数）
	int cap;          // 总容量（即最多能容纳的数据元素的个数）

} *vector;


vector create(int init_cap)
{
	vector v;

	v = malloc(sizeof(*v));

	if(NULL == v)
	{
		perror("malloc error");
		return NULL;
	}

	v->data = malloc(init_cap * sizeof(elem_type));

	if(NULL == v->data)
	{
		perror("malloc error");
		return NULL;
	}

	v->cap = init_cap;
	v->size = 0;
}


// 销毁
void destroy(vector v)
{
	free(v->data);
	free(v);
}


// 清空
void clear(vector v)
{
	v->size = 0;
}


// 判空
int empty(vector v)
{
	return !(v->size);
}


// 求长度
int size(vector v)
{
	return v->size;
}


// 扩容
void expand(vector v, int inc_cap)
{
	v->cap += inc_cap;

	v->data = realloc(v->data, v->cap * sizeof(elem_type));

	if(v->data == NULL)
	{
		perror("realloc error");
	}
}


// 插入一个新的数据元素（尾插），时间复杂度为 O(1)
void push_back(vector v, elem_type data)
{
	if(v->size == v->cap)
	{
		// 如果容量不够就扩容
		expand(v, 100);
	}

	v->data[v->size] = data;
	v->size++;
}


// 插入一个新的数据元素（头插），时间复杂度为 O(n)
void push_front(vector v, elem_type data)
{
	if(v->size == v->cap)
	{
		// 如果容量不够就扩容
		expand(v, 100);
	}

	int i;
	for(i = v->size - 1; i >= 0; i--)
		v->data[i + 1] = v->data[i];

	v->data[0] = data;
	v->size++;
}


// 插入一个新的数据元素（中插），时间复杂度为 O(n)
void insert(vector v, int pos, elem_type data)
{	
	if(pos < 0 || pos > v->size)
	{
		fprintf(stderr, "insert error");
		return;
	}

	if(v->size == v->cap)
	{
		// 如果容量不够就扩容
		expand(v, 100);
	}

	// 将 pos 位置之后的所有元素往后挪动
	int i;
	for(i = v->size - 1; i >= pos; i--)
		v->data[i + 1] = v->data[i];

	v->data[pos] = data;
	v->size++;
}


// 删除一个数据元素（根据数据元素的位置），时间复杂度为 O(n)
int erase(vector v, int pos)
{
	if(pos < 0 || pos >= v->size)
		return 0;

	int i;

	// 将 pos 位置之后的所有元素依次往前挪动
	for(i = pos + 1; i < v->size; i++)
		v->data[i - 1] = v->data[i];

	v->size--;

	return 1;
}


// 删除一个数据元素（根据数据元素的值），时间复杂度为 O(n)
int remove2(vector v, elem_type data)
{
	int i;
	for(i = 0; i < v->size; i++)
	{
		if(v->data[i] == data)
			return erase(v, i);
	}

	return 0;
}


// 修改某个数据元素的值，时间复杂度为 O(n)
int update(vector v, elem_type old_val, elem_type new_val)
{
	int i;
	for(i = 0; i < v->size; i++)
	{
		if(v->data[i] == old_val)
		{
			v->data[i] = new_val;
			return 1;
		}
	}

	return 0;
}


// 随机访问某个数据元素（即根据数据元素的位置进行访问），时间复杂度为 O(1)
elem_type* at(vector v, int pos)
{
	return v->data + pos;
}


// 查找某个数据
elem_type* find(vector v, elem_type data)
{
	int i;
	for(i = 0; i < v->size; i++)
	{
		if(v->data[i] == data)
			return v->data + i;
	}

	return NULL;
}


// 逆序
void reverse(vector v)
{
	int i;
	elem_type tmp;

	for(i = 0; i < v->size / 2; i++) 
	{
		tmp = v->data[i];
		v->data[i] = v->data[v->size - i - 1];
		v->data[v->size - i - 1] = tmp;
	}
}


// 排序（采用插入排序算法）
void sort(vector v, int(*cmp)(const elem_type*, const elem_type*))
{
	int i, j;
	elem_type k;
	
	for(i = 1; i < v->size; i++)
	{
		k = v->data[i];

		for(j = i - 1; j >= 0; j--)
		{
			if(cmp(v->data + j, &k) > 0)
				v->data[j + 1] = v->data[j];
			else break;
		}

		v->data[j + 1] = k;
	}
}



int cmp1(const elem_type* a, const elem_type* b)
{
	return *b - *a;
}


int main()
{
	vector v1;

	v1 = create(100);

	reverse(v1);

	push_back(v1, 5);
	push_front(v1, 1);

	printf("顺序表长度：%d\n", size(v1));

	clear(v1);

	if(empty(v1))
		printf("顺序表空空如也！\n");

	push_back(v1, 3);
	push_front(v1, 4);
	insert(v1, 0, 2);
	insert(v1, 3, 6);

	// 将顺序表 v1 中的第 2 个数据赋值为 777
	*at(v1, 2) = 777;
	/*
	elem_type* p = at(v1, 2);
	*p = 777;
	*/

	if(!empty(v1))
		printf("顺序表非空！\n");

	printf("顺序表长度：%d\n", size(v1));

	for(int i = 0; i < size(v1); i++)
	{
		printf("%d ", *at(v1, i));
	}
	printf("\n");

	reverse(v1);

	for(int i = 0; i < size(v1); i++)
	{
		printf("%d ", *at(v1, i));
	}
	printf("\n");

	sort(v1, cmp1);  // 降序
	
	for(int i = 0; i < size(v1); i++)
	{
		printf("%d ", *at(v1, i));
	}
	printf("\n");

	erase(v1, 0);
	erase(v1, 0);

	remove2(v1, 3);

	int n;
	printf("请输入一个要删除的整数：");
	scanf("%d", &n);

	if(remove2(v1, n))
		printf("删除成功！\n");
	else
		printf("数据不存在，删除失败！\n");

	
	update(v1, 5, 9);
	update(v1, 8, 18);

	if(!find(v1, 8))
	{
		printf("8 不存在！\n");	
	}

	*find(v1, 2) = 222;

	for(int i = 0; i < size(v1); i++)
	{
		printf("%d ", *at(v1, i));
	}
	printf("\n");

	destroy(v1);
	
	return 0;
}
