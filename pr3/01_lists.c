
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>// bool,
struct List
{
	struct List* NextBlock;
	double Data;
};
struct node
{
	struct node* NextBlock;
	double Data;
};
void init(struct List** l)
{
	*l = (struct List*)malloc(sizeof(struct List));//��������� ������ ��� ������ ������
	(*l)->NextBlock = NULL;//������ ���� ������
	(*l)->Data = 2147483648;
}
int push_back(struct List* l, int value)
{
	if (l->Data == 2147483648)
	{
		l->Data = value;
		return 0;
	}
	struct List* Temp = (struct List*)malloc(sizeof(struct List));
	Temp = l;
	while (Temp->NextBlock != NULL)//�� Temp �������� NextBlock
		Temp = Temp->NextBlock;
	Temp->NextBlock = (struct List*)malloc(sizeof(struct List));
	Temp = Temp->NextBlock;
	Temp->Data = value;
	Temp->NextBlock = NULL;
	return 0;
}
struct node* find(struct List* l, int value)
{
	struct List* Temp = l;
	while (1)
	{
		if (Temp == NULL)
			return NULL;
		else
		{
			if ((Temp->Data) == value)
				return ((struct node*)l);
		}
		Temp = Temp->NextBlock;
	}
}
int push_front(struct List** l, int value)
{
	struct List* Temp = (struct List*)malloc(sizeof(struct List));
	Temp->Data = value;
	Temp->NextBlock = (*l);
	(*l) = Temp;
	return 0;
}
int insert_after(struct node* l, int value)
{
	struct List* Temp = (struct List*)malloc(sizeof(struct List)), * Temp2;
	Temp2 = (struct List*)l->NextBlock;
	l->NextBlock = (struct node*)Temp;
	Temp->Data = value;
	Temp->NextBlock = Temp2;
	return 0;
}
int remove_node(struct List* l, int value)
{
	struct List* Temp = l;
	if (l != NULL)
	{
		while (1)
		{
			if ((Temp->NextBlock) == NULL)
				return 1;
			if ((Temp->NextBlock->Data) == value)
			{
				struct List* Temp2 = (struct List*)malloc(sizeof(struct List));
				Temp2 = Temp->NextBlock->NextBlock;
				free(Temp->NextBlock);
				Temp->NextBlock = Temp2;
				return 0;
			}
			Temp = Temp->NextBlock;
		}
	}
	else
		return 1;
}
void clean(struct List* l)
{
	struct List* Temp = l;
	do
	{
		Temp = Temp->NextBlock;
		free(l);//������������ ������ ���������� ����
		l = Temp;//������������ ���������
	} while (l != NULL);
}

bool is_empty(struct List* l)
{
	if (l == NULL)
		return 0;
	else
		return 1;
}

void print(struct List* l)
{
	while (l != NULL)
	{
		printf("%.0lf ", l->Data);
		l = l->NextBlock;
	}
	printf("\n");
}
int main()
{
	struct List* l, * Temp;
	int N, i;
	double a, b;
	scanf("%d", &N);//1
	init(&l);//2
	for (i = 0; i < N; i++)
	{
		scanf("%lf", &a);
		push_back(l, a);
	}
	print(l);//3
	for (i = 0; i < 3; i++)//4
	{
		scanf("%lf", &a);
		if (find(l, a) == NULL)
			printf("0");
		else
			printf("1");
		if (i != 2)
			printf(" ");
		else
			printf("\n");
	}
	scanf("%lf", &a);//5
	push_back(l, a);
	print(l);//6
	scanf("%lf", &a);//7
	push_front(&l, a);
	print(l);//8
	scanf("%lf", &a);//9
	scanf("%lf", &b);
	struct node* el = (struct node*)l;
	while (a != 1)
	{
		el = el->NextBlock;
		a--;
	}
	insert_after(el, b);
	print(l);//10
	scanf("%lf", &a);//11
	if (l->Data == a)
	{
		Temp = l->NextBlock;
		free(l);
		l = Temp;
	}
	else
		remove_node(l, a);
	print(l);//12
	clean(l);//13
	return 1;
}

