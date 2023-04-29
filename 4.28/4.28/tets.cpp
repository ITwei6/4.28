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
//���Կ���������C����ʵ��ʱ��Stack��ز������������¹��ԣ�
//ÿ�������ĵ�һ����������Stack*
//�����б���Ҫ�Ե�һ��������⣬��Ϊ�ò������ܻ�ΪNULL
//�����ж���ͨ��Stack* ��������ջ��
//����ʱ���봫��Stack�ṹ������ĵ�ַ
//�ṹ����ֻ�ܶ��������ݵĽṹ���������ݵķ������ܷ��ڽṹ���У������ݺͲ�������
//�ķ�ʽ�Ƿ��뿪�ģ�����ʵ�����൱����һ�㣬�漰������ָ��������Բ�ע����ܾͻ��
//��
//2. C++ʵ��
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
			perror("realloc����ռ�ʧ��!!!");
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