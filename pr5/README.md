# Отчет по практической работе №5	
### 1 Введение
Целью данной работы является ознакомление и получение первичных навыков взаимодействия с бинарными деревьями поиска.

Шаги выполнения лабораторной работы представлены ниже:

1) Должны быть выполнены предыдущие работы


2) Прочитать про двусвязные списки на СИ


3) Написать программу


4) Настроить pipeline


5) Написать отчет по работе в разметке Markdown (README.md)


6) Залить на gitlab и убедиться, что pipeline проходит успешно


7) Защитить работу у преподавателя


Реализовать программу, функции, которых представлены в таблице 1.

Таблица 1 - Функции
| Номер | Задание |
| ------------- | ------------- |
|  1  | создает пустое дерево, считывает 4 элемента ai, |ai| <= 2147483647 и заносит их в дерево;  |
|  2  | выводит дерево (используя функцию print_tree) и пустую строку;  |
|  3  | считывает 3 элемента ai, ai <= 2147483647 и заносит их в дерево;  |
|  4  | выводит дерево и пустую строку;  |
|  5  | считывает m1, m1 <= 2147483647 и ищет элемент с заданным значением в дереве; выводит через пробел значение предка и потомков найденного элемента, если нет значений предка или потомков вывести "_" вместо таких значений; вывести "-", если элемент не найден; вывести пустую строку;  |
|  6  | считывает m2, m2 <= 2147483647 и ищет элемент с заданным значением в дереве; выводит через пробел значение предка и потомков найденного элемента, если нет значений предка или потомков вывести "_" вместо таких значений; вывести "-", если элемент не найден; вывести пустую строку;  |
|  7  | считывает m3, m3 <= 2147483647 и удаляет из дерева элемент с заданным значением (если такой элемент есть);  |
|  8 | выводит дерево и пустую строку;  |
|  9  | выполняет левый поворот дерева относительно корня, пока это возможно;  |
|  10  | выводит дерево и пустую строку;  |
|  11  | выполняет правый поворот дерева относительно корня, пока это возможно;  |
|  12  | выводит дерево и пустую строку;  |
|  13  | выводит на экран количество элементов в дереве и пустую строку  |
|  14  |  очищает дерево  |
|  15  |  выводит дерево и пустую строку;

### 2 Ход работы
#### 2.1 Работа с кодом
Используя IDE Visual Studio и CLion напишем коды программ.

Ниже функции, которые нужно реализовать работы с бинарным деревом поиска:

```c
// инициализация пустого списка
// Инициализация дерева
void init(tree* t);

// Удалить все элементы из дерева
void clean(tree* t);

// Поиск элемента по значению. Вернуть NULL если элемент не найден
node* find(tree* t, int value);

// Вставка значения в дерево:
// 0 - вставка выполнена успешно
// 1 - элемент существует
// 2 - не удалось выделить память для нового элемента
int insert(tree* t, int value);

// Удалить элемент из дерева:
// 0 - удаление прошло успешно
// 1 - нет элемента с указанным значением
int remove_node(tree* t, int value);

// Удалить минимальный элемент из поддерева, корнем которого является n
// Вернуть значение удаленного элемента
int remove_min(node* n);

// Выполнить правое вращение поддерева, корнем которого является n:
// 0 - успешно выполненная операция
// 1 - вращение невозможно
int rotate_right(node* n);

// Выполнить левое вращение поддерева, корнем которого является n:
// 0 - успешно выполненная операция
// 1 - вращение невозможно
int rotate_left(node* n);

// Вывести все значения из поддерева, корнем которого является n
// по уровням начиная с корня.
// Каждый уровень выводится на своей строке.
// Элементы в строке разделяются пробелом. Если элемента нет, заменить на _.
// Если дерево пусто, вывести -
void print(node* n);

// Вывести все значения дерева t, аналогично функции print
void print_tree(tree* t);

```
Функция, осуществляющая инициализацию дерева представлена ниже:
```c
void init(struct Tree** t)
{
	*t = (struct Tree*)malloc(sizeof(struct Tree));
	(*t)->Right = NULL;
	(*t)->Left = NULL;
	(*t)->Data = 2147483648;
}
```
Функция вставки значения в дерево представлена ниже:
```c
int insert(struct Tree* t, int value)
{
	if (t->Data == 2147483648)
	{
		t->Data = value;
		return 0;
	}
	if (t->Data == value)
		return 1;
	if (value > (t->Data))
	{
		if ((t->Right) != NULL)
			return(insert(t->Right, value));
		else
		{
			t->Right = (struct Tree*)malloc(sizeof(struct Tree));
			t->Right->Right = NULL;
			t->Right->Left = NULL;
			t->Right->Data = value;
			return 0;
		}
	}
	else
	{
		if ((t->Left) != NULL)
			return(insert(t->Left, value));
		else
		{
			t->Left = (struct Tree*)malloc(sizeof(struct Tree));
			t->Left->Right = NULL;
			t->Left->Left = NULL;
			t->Left->Data = value;
			return 0;
		}
	}
}
```
Структура поиска элемента дерева представлена ниже:
```c
struct Tree* find(struct Tree* t, int value)
{
	if (t->Data == value)
		return t;
	else
	{
		if (value < t->Data)
		{
			if (t->Left != NULL)
				return(find(t->Left, value));
			else
				return NULL;
		}
		else
		{
			if (t->Right != NULL)
				return(find(t->Right, value));
			else
				return NULL;
		}
	}
}
```
Структура для нахождения потомков введенного с клавиатуры элемента представлена ниже:
```c
int find_with_output(struct Tree* t, int value)
{
	if (t->Data == value)
	{
		printf("_ ");
		if (t->Left != NULL)
			printf("%d ", (int)t->Left->Data);
		else
			printf("_ ");
		if (t->Right != NULL)
			printf("%d", (int)t->Right->Data);
		else
			printf("_");
	}
	else
	{
		if (value < t->Data)
		{
			if (t->Left != NULL)
			{
				if (t->Left->Data == value)
				{
					printf("%d ", (int)t->Data);
					if ((t->Left->Left) != NULL)
						printf("%d ", (int)t->Left->Left->Data);
					else
						printf("_ ");
					if ((t->Left->Right) != NULL)
						printf("%d", (int)t->Left->Right->Data);
					else
						printf("_");
				}
				else
					return(find_with_output(t->Left, value));
			}
			else
				return 1;
		}
		else
		{
			if (t->Right != NULL)
			{
				if (t->Right->Data == value)
				{
					printf("%d ", (int)t->Data);
					if ((t->Right->Left) != NULL)
						printf("%d ", (int)t->Right->Left->Data);
					else
						printf("_ ");
					if ((t->Right->Right) != NULL)
						printf("%d", (int)t->Right->Right->Data);
					else
						printf("_");
				}
				else
					return(find_with_output(t->Right, value));
			}
			else
				return 1;
		}
	}
	return 0;
}
```
Результат работы программы  представлен на рисунке 1.

![](https://sun9-44.userapi.com/impg/f5-cp9-cXtb5Z3MN-Sv07dIj-tqR-bUwan-5kg/H1GIs2b3DZY.jpg?size=674x473&quality=96&sign=556dc37557f8cbdba649e3338f6807f7&type=album)

Рисунок 1 — Результат работы программы 


#### 2.2 Работа с GitLab
Далее требуется настроить pipeline-тест. Для этого нужно добавить/раскомментировать строки в  gitlab-ci.yml, как это представлено ниже:
```c
# Пятая практическая работа

pr5_easy_test:
  stage: pr5
  script:
  - gcc pr5/01_*.c
  - PYTHONIOENCODING=utf-8 python3 pr5/tests/checker.py 0

pr5_middle_test:
  stage: pr5
  script:
  - gcc pr5/01_*.c
  - PYTHONIOENCODING=utf-8 python3 pr5/tests/checker.py 1
  allow_failure: true

```

Внесем последние в локальный проект и перешлем его в GitLab (commit and push).
Результаты проверки представлены на рисунке 2.

Рисунок 2 — Результаты pipeline-проверки

![](https://sun9-39.userapi.com/impg/BisLz7WDVcMFtlqZXSng1ha9kd5idK6xsm2wvg/G-_E-7Ip0TA.jpg?size=246x161&quality=96&sign=fe501cde93a46d3469d4a55aabd4af60&type=album)


### 3 Заключение
В ходе выполнения практической работы, были изучены основы работы с деревьями, а также успешно разработана программа, заданная вариантом, на языке программирования С. Pipeline был успешно пройден, что говорит о том, что код написан правильно.

### Приложение А

Листинг кода представлен ниже:

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

struct Tree
{
	struct Tree* Right;
	struct Tree* Left;
	double Data;
};
void init(struct Tree** t)
{
	*t = (struct Tree*)malloc(sizeof(struct Tree));
	(*t)->Right = NULL;
	(*t)->Left = NULL;
	(*t)->Data = 2147483648;
}
void clean(struct Tree* t)
{
	if (t != NULL)
	{
		if (t->Right != NULL)
			clean(t->Right);
		if (t->Left != NULL)
			clean(t->Left);
		free(t);
	}
}
struct Tree* find(struct Tree* t, int value)
{
	if (t->Data == value)
		return t;
	else
	{
		if (value < t->Data)
		{
			if (t->Left != NULL)
				return(find(t->Left, value));
			else
				return NULL;
		}
		else
		{
			if (t->Right != NULL)
				return(find(t->Right, value));
			else
				return NULL;
		}
	}
}
int find_with_output(struct Tree* t, int value)
{
	if (t->Data == value)
	{
		printf("_ ");
		if (t->Left != NULL)
			printf("%d ", (int)t->Left->Data);
		else
			printf("_ ");
		if (t->Right != NULL)
			printf("%d", (int)t->Right->Data);
		else
			printf("_");
	}
	else
	{
		if (value < t->Data)
		{
			if (t->Left != NULL)
			{
				if (t->Left->Data == value)
				{
					printf("%d ", (int)t->Data);
					if ((t->Left->Left) != NULL)
						printf("%d ", (int)t->Left->Left->Data);
					else
						printf("_ ");
					if ((t->Left->Right) != NULL)
						printf("%d", (int)t->Left->Right->Data);
					else
						printf("_");
				}
				else
					return(find_with_output(t->Left, value));
			}
			else
				return 1;
		}
		else
		{
			if (t->Right != NULL)
			{
				if (t->Right->Data == value)
				{
					printf("%d ", (int)t->Data);
					if ((t->Right->Left) != NULL)
						printf("%d ", (int)t->Right->Left->Data);
					else
						printf("_ ");
					if ((t->Right->Right) != NULL)
						printf("%d", (int)t->Right->Right->Data);
					else
						printf("_");
				}
				else
					return(find_with_output(t->Right, value));
			}
			else
				return 1;
		}
	}
	return 0;
}
int insert(struct Tree* t, int value)
{
	if (t->Data == 2147483648)
	{
		t->Data = value;
		return 0;
	}
	if (t->Data == value)
		return 1;
	if (value > (t->Data))
	{
		if ((t->Right) != NULL)
			return(insert(t->Right, value));
		else
		{
			t->Right = (struct Tree*)malloc(sizeof(struct Tree));
			t->Right->Right = NULL;
			t->Right->Left = NULL;
			t->Right->Data = value;
			return 0;
		}
	}
	else
	{
		if ((t->Left) != NULL)
			return(insert(t->Left, value));
		else
		{
			t->Left = (struct Tree*)malloc(sizeof(struct Tree));
			t->Left->Right = NULL;
			t->Left->Left = NULL;
			t->Left->Data = value;
			return 0;
		}
	}
}
int deep(struct Tree* t)
{
	int r = 0, l = 0;
	if ((t->Right) != NULL)
		r = deep(t->Right);
	if ((t->Left) != NULL)
		l = deep(t->Left);
	if (r > l)
		return (r + 1);
	return (l + 1);
}
int remove_node(struct Tree** t, int value)
{
	if ((*t)->Data == value)
	{
		if ((*t)->Right != NULL)
		{
			struct Tree* Temp = (*t)->Right, * Temp2;
			if (Temp->Left != NULL)
			{
				while (Temp->Left->Left != NULL)
					Temp = Temp->Left;
				(*t)->Data = Temp->Left->Data;
				Temp2 = Temp->Left;
				Temp->Left = Temp2->Right;
				free(Temp2);
			}
			else
			{
				struct Tree* Temp;
				(*t)->Data = (*t)->Right->Data;
				Temp = (*t)->Right;
				(*t)->Right = (*t)->Right->Right;
				free(Temp);
			}
		}
		else
		{
			struct Tree* Temp;
			Temp = (*t);
			(*t) = (*t)->Left;
			free(Temp);
			Temp = NULL;
		}
		return 0;
	}
	else
	{
		if (value < ((*t)->Data))
		{
			if ((*t)->Left != NULL)
				return(remove_node(&((*t)->Left), value));
			else
				return 1;
		}
		else
		{
			if (((*t)->Right) != NULL)
				return(remove_node(&((*t)->Right), value));
			else
				return 1;
		}
	}
}
int remove_min(struct Tree* t)
{
	struct Tree* Temp = t, * Temp2;
	if (Temp->Left != NULL)
	{
		while (Temp->Left->Left != NULL)
			Temp = Temp->Left;
		Temp2 = Temp->Left;
		Temp->Left = Temp2->Right;
		free(Temp2);
	}
	else
	{
		Temp = t->Right;
		free(t);
		t = Temp;
	}
	return 0;
}
int rotate_right(struct Tree** t)
{
	if (*t == NULL)
		return 1;
	struct Tree* A, * B, * C = (*t)->Right, * x = (*t)->Left, * y = (*t), * Temp = (struct Tree*)malloc(sizeof(struct Tree));
	if (x != NULL)
	{
		A = x->Left;
		B = x->Right;
	}
	else
		return 1;
	Temp->Right = y;
	Temp->Left = A;
	Temp->Right->Right = C;
	Temp->Right->Left = B;
	Temp->Data = x->Data;
	free(x);
	(*t) = Temp;
	return 0;
}
int rotate_left(struct Tree** t)
{
	if (*t == NULL)
		return 1;
	struct Tree* A = (*t)->Left, * B, * C, * x = (*t), * y = (*t)->Right, * Temp = (struct Tree*)malloc(sizeof(struct Tree));
	if (y != NULL)
	{
		B = y->Left;
		C = y->Right;
	}
	else
		return 1;
	Temp->Right = C;
	Temp->Left = x;
	Temp->Left->Right = B;
	Temp->Left->Left = A;
	Temp->Data = y->Data;
	free(y);
	(*t) = Temp;
	return 0;
}
int print_tree(struct Tree* t)
{
	if (t == NULL)
	{
		printf("-\n");
		return 1;
	}
	struct Tree* Temp = t;
	int Rang = 0, i, j, k, sk;
	int* comb;
	Rang = deep(t);
	comb = (int*)malloc(sizeof(int));
	for (i = 0; i < Rang; i++)
	{
		if (i != 0)
		{
			comb = (int*)realloc(comb, i * sizeof(int));
			for (j = 0; j < i; j++)
				comb[j] = 0;
		}
		j = 1;
		sk = i;
		while (sk != 0)
		{
			j = j * 2;
			sk--;
		}
		while (j != 0)
		{
			k = 0;
			Temp = t;
			for (k = 0; k < i; k++)
			{
				if (comb[k] == 0)
				{
					if ((Temp->Left) != NULL)
						Temp = Temp->Left;
					else
					{
						k = -1;
						break;
					}
				}
				else
				{
					if ((Temp->Right) != NULL)
						Temp = Temp->Right;
					else
					{
						k = -1;
						break;
					}
				}
			}
			if (i != 0)
			{
				sk = i - 1;
				comb[sk]++;
				while (1)
				{
					if (comb[sk] == 2)
					{
						comb[sk] = 0;
						sk--;
						if (sk < 0)
							break;
						else
							comb[sk]++;
					}
					else
						break;
				}
			}
			if (k == -1)
				printf("_");
			else
				printf("%d", (int)Temp->Data);
			j--;
			if (j != 0)
				printf(" ");
		}
		printf("\n");
	}
	return 1;
}
int all(struct Tree* t)
{
	if (t == NULL)
		return 0;
	int r, l;
	l = all(t->Left);
	r = all(t->Right);
	return (l + r + 1);
}
int main()
{
	struct Tree* t;
	int i;
	double a;
	init(&t);//1 пункт
	for (i = 0; i < 4; i++)
	{
		scanf("%lf", &a);
		insert(t, a);
	}
	print_tree(t);//2 пункт
	printf("\n");
	for (i = 0; i < 3; i++)//3 пункт
	{
		scanf("%lf", &a);
		insert(t, a);
	}
	print_tree(t);//4 пункт
	printf("\n");
	for (i = 0; i < 2; i++)
	{
		scanf("%lf", &a);//5 и 6 пункт
		a = find_with_output(t, a);
		if (a == 1)
			printf("-");
		printf("\n\n");
	}
	scanf("%lf", &a);//7 пункт
	remove_node(&t, a);
	print_tree(t);//8 пункт
	printf("\n");
	while (1)//9 пункт
	{
		a = rotate_left(&t);
		if (a == 1)
			break;
	}
	print_tree(t);//10 пункт
	printf("\n");
	while (1)//11 пункт
	{
		a = rotate_right(&t);
		if (a == 1)
			break;
	}
	print_tree(t);//12 пункт
	printf("\n");
	printf("%d\n\n", all(t));//13 пункт
	clean(t);//14 пункт
	t = NULL;
	print_tree(t);//15 пункт
	return 0;

}
```


