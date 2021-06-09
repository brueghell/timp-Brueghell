# Отчет по практической работе №3
### 1 Введение
Целью данной работы является ознакомление и получение первичных навыков взаимодействия с односвязными списками.

Шаги выполнения лабораторной работы представлены ниже:

1.Должны быть выполнены предыдущие работы

2.Прочитать про односвязные списки на СИ

3.Написать программу

4.Настроить pipeline

5.Написать отчет по работе в разметке Markdown (README.md)

6.Залить на gitlab и убедиться, что pipeline проходит успешно


7.Защитить работу у преподавателя


Требуется создать программу с функциями, которые представлены в таблице 1.

Таблица 1 - Функции
| Номер | Задание |
| ------------- | ------------- |
|  1  | Считывание количества элементов n, 0 < n <= 2147483647;  |
|  2  | Создание пустого списка, считывание n элементов a, a <= 2147483647 и заносение их в список;  |
|  3  | Вывод содержимого списка, используя функцию print;  |
|  4  | Считывание k1, k2, k3 (k <= 2147483647) и вывод "1", если в списке существует элемент с таким значением и "0", если нет (вывод через пробел, например "1 0 1");  |
|  5  | Считывание m, m <= 2147483647 и вставка его в конец списка;  |
|  6  | Вывод содержимого списка, используя функцию print;  |
|  7  | Считывание t, t <= 2147483647 и вставка его в начало списка;  |
|  8 | Вывод содержимого списка, используя функцию print;  |
|  9  | Считывание j и x (0 < j <= 2147483647, x <= 2147483647) и вставка значения x после j-ого элемента списка;  |
|  10  | Вывод содержимого списка, используя функцию print;  |
|  11  | Считывание z, z <= 2147483647 и удаление первого элемента (при его наличии), хранящий значение z из списка;  |
|  12  | Вывод содержимого списка, используя функцию print;  |
|  13  | Очищение списка  |



### 2 Ход работы
#### 2.1 Работа с кодом
Используя IDE Visual Studio и CLion напишем коды программ.

Код для программы	 выглядит следующим образом:
```с
#define _CRT_SECURE_NO_WARNINGS
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
	*l = (struct List*)malloc(sizeof(struct List));//выделение памяти под корень списка
	(*l)->NextBlock = NULL;//первый узел списка
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
	while (Temp->NextBlock != NULL)//из Temp получаем NextBlock
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
		free(l);//освобождение памяти удаленного узла
		l = Temp;//переставляем указатель
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
```
Результат работы программы  представлен на рисунке 1.

![](https://sun9-33.userapi.com/impf/uuvM8Iqnf4pqBv8LkrweFvjEeqrwvecli-eNjw/9bvkSsdDe6M.jpg?size=678x194&quality=96&sign=06713cc24c3dd28bc408d6bf8a4fe335&type=album)

Рисунок 1 — Результат работы программы 

Изначально вводится количество элементов. Далее, вводятся значения элементов и заносятся в список. С помощью функции print эти данные выводятся. Вводится три значения и выводит "1", если в списке существует элемент с таким значением и "0", если нет. Далее вводится значение, которое встанет на 0-ое место в списке, а также значения, которое встанет на последнее место в списке. Считывает j и x и вставляет значение x после j-ого элемента списка. Далее считывает z, и удаляет z-й элемент.  

#### 2.2 Работа с GitLab

Внесем последние в локальный проект и перешлем его в GitLab (commit and push).
Результаты проверки представлены на рисунке 3.

Рисунок 3 — Результаты pipeline-проверки

![](https://sun9-52.userapi.com/impf/Ar78Sxhmp1m5iauJiVpWjKXCFv0KjKsNoGbA3w/p52-dNR38Jc.jpg?size=227x215&quality=96&sign=6ebc8a49778792a6be61314d982b037c&type=album)


### 3 Заключение
В ходе выполнения практической работы, были изучены основы односвязных списков, а также успешно разработаны программы, заданные вариантом.


