#include <iostream>
#include "test.h"

void A:: Print()
	{
		cout << _a << endl;
	}

int main()
{
	A a1;
	a1.Print();
}
class Data
{
public:
	
	Data(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year ;
	int _month;
	int _day;
};
//可以看到，在用C语言实现时，Stack相关操作函数有以下共性：
//每个函数的第一个参数都是Stack*
//函数中必须要对第一个参数检测，因为该参数可能会为NULL
//函数中都是通过Stack* 参数操作栈的
//调用时必须传递Stack结构体变量的地址
//结构体中只能定义存放数据的结构，操作数据的方法不能放在结构体中，即数据和操作数据
//的方式是分离开的，而且实现上相当复杂一点，涉及到大量指针操作，稍不注意可能就会出
//错。
//2. C++实现
typedef int DataType;
typedef struct Stack
{
	DataType* array;
	int capacity;
	int size;
}Stack;
void StackInit(Stack* ps)
{
	assert(ps);
	ps->array = (DataType*)malloc(sizeof(DataType) * 3);
	if (NULL == ps->array)
	{
		assert(0);
		return;
	}
	
		ps->capacity = 3;
	ps->size = 0;
}
void StackDestroy(Stack* ps)
{
	assert(ps);
	if (ps->array)
	{
		free(ps->array);
		ps->array = NULL;
		ps->capacity = 0;
		ps->size = 0;
	}
}
void CheckCapacity(Stack* ps)
{
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity * 2;
		DataType* temp = (DataType*)realloc(ps->array,
			newcapacity * sizeof(DataType));
		if (temp == NULL)
		{
			perror("realloc申请空间失败!!!");
			return;
		}
		ps->array = temp;
		ps->capacity = newcapacity;
	}
}
void StackPush(Stack* ps, DataType data)
{
	assert(ps);
	CheckCapacity(ps);
	ps->array[ps->size] = data;
	ps->size++;
}
int StackEmpty(Stack* ps)
{
	assert(ps);
	return 0 == ps->size;
}
void StackPop(Stack* ps)
{
	if (StackEmpty(ps))
		return;
	ps->size--;
}
DataType StackTop(Stack* ps)
{
	assert(!StackEmpty(ps));
	return ps->array[ps->size - 1];
	
	
}
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->size;
}
int main()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	printf("%d\n", StackTop(&s));
	printf("%d\n", StackSize(&s));
	StackPop(&s);
	StackPop(&s);
	printf("%d\n", StackTop(&s));
	printf("%d\n", StackSize(&s));
	StackDestroy(&s);
	return 0;
}