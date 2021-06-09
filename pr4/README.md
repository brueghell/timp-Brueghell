# Отчет по практической работе №4	
### 1 Введение
Целью данной работы является ознакомление и получение первичных навыков взаимодействия с двусвязными списками.

Шаги выполнения лабораторной работы представлены ниже:

1) Должны быть выполнены предыдущие работы


2) Прочитать про двусвязные списки на СИ


3) Написать программу


4) Настроить pipeline


5) Написать отчет по работе в разметке Markdown (README.md)


6) Залить на gitlab и убедиться, что pipeline проходит успешно


7) Защитить работу у преподавателя


Требуется создать программу с функциями, которые представлены в таблице 1.

Таблица 1 - Функции
| Номер | Задание |
| ------------- | ------------- |
|  1  | Считывание количества элементов n, 0 < n <= 2147483647;  |
|  2  | Создание пустого списка, считывание n элементов a, a <= 2147483647 и заносение их в список;  |
|  3  | Вывод содержимого списка, используя функцию print;  |
|  4  | Считывание k1, k2, k3 (k <= 2147483647) и вывод "1", если в списке существует элемент с таким значением и "0", если нет (вывод через пробел, например "1 0 1");  |
|  5  | Считывание m, m <= 2147483647 и вставка его в конец списка;  |
|  6  | Вывод содержимого списка, используя функцию print_invers;  |
|  7  | Считывание t, t <= 2147483647 и вставка его в начало списка;  |
|  8 | Вывод содержимого списка, используя функцию print;  |
|  9  | Считывание j и x (0 < j <= 2147483647, x <= 2147483647) и вставка значения x после j-ого элемента списка;  |
|  10  | Вывод содержимого списка, используя функцию print_invers;  |
|  11  | Считывание u и y (0 < u <= 2147483647, |y| <= 2147483647) и вставка значения y перед u-ым элементом списка;  |
|  12  | Вывод содержимого списка, используя функцию print;  |
|  13  | Считывание z, z <= 2147483647 и удаление первый элемент (при его наличии), хранение значения z из списка;  |
|  14  |  Вывод содержимого списка, используя функцию print_invers;  |
|  15  |  Считывание r, r <= 2147483647 и удаление последнего элемента (при его наличии), хранение значения r из списка;  |
|  16  |  Вывод содержимого списка, используя функцию print;  |
|  17  |  Очищение списка;  |


### 2 Ход работы
#### 2.1 Работа с кодом
Используя IDE Visual Studio и CLion напишем коды программ.

Инициализация списка представлена ниже:
```с
struct Line
{
	struct Line* Front;
	struct Line* Back;
	double Data;
};
void init(struct Line** l)//получаем значение, взятое по адресу адреса
{
	*l = (struct Line*)malloc(sizeof(struct Line));
	(*l)->Front = NULL;
	(*l)->Back = NULL;
	(*l)->Data = 2147483648;
}
```

Изначально происходит создание структуры и ее инициализация. Освобождаем память и присваем значения для пустых узлов и максимальное значение данных, которое может содержать узел.

Заполнение списка представлено ниже:

```с
int push_front(struct Line** l, int value)
{
	struct Line* Temp = (struct Line*)malloc(sizeof(struct Line));//при этом здесь **l--это значение
	Temp->Data = value;//l--конкретно двойной адрес, *l--адрес блока, **l--блок
	Temp->Front = (*l);//то есть, в следующем элементе записан адрес начального эл-та списка
	Temp->Back = NULL;
	Temp->Front->Back = Temp;//указатель от прошлого первого элемента
	(*l) = Temp;//вот у нас есть список, засунутый в Temp(адрес), мы берём присваиваем адресу l адрес Temp
	return 0;
}
```
Изначально происходит освобождение памяти для Temp. Далее значение Data мы заполняем с клавиатуры, а во Front будет записан следующий адрес начального эл-та списка. После идет присваивание Back к null для проверки, первым ли является данный узел. После мы имеем список, засунутый в Temp(адрес), который мы берём и присваиваем адресу l адрес Temp.

Функция print представлена ниже:
 
```с
void print(struct Line* l)
{
	while (l != NULL)
	{
		printf("%.0lf ", l->Data);
		l = l->Front;
	}
	printf("\n");
}
```

Результат работы программы  представлен на рисунке 1.

![](https://sun9-22.userapi.com/impg/uWuMurfgbWksds9CyrMLZ-0iRbBNIAuA7VnigQ/JOzCgtMj3Cs.jpg?size=679x246&quality=96&sign=7aa9fa9fb419fcf23af5ebe06c09d841&type=album)

Рисунок 1 — Результат работы программы 


#### 2.2 Работа с GitLab

Внесем последние в локальный проект и перешлем его в GitLab (commit and push).
Результаты проверки представлены на рисунке 2.

Рисунок 2 — Результаты pipeline-проверки

![](https://sun9-34.userapi.com/impg/FnvoLGQF526iv7VxNkNuq9O8PGimpGxrlXuDCA/Ed9N1yzEk6k.jpg?size=272x229&quality=96&sign=2ea11f3c5a2e1a87acd53d9e15c8731f&type=album)


### 3 Заключение
В ходе выполнения практической работы, были изучены основы двусвязных списков, а также успешно разработана программа, заданная вариантом. Pipeline был успешно пройден, что говорит о том, что код написан правильно.

### Приложение А

Листинг кода представлен ниже:

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
struct Line
{
	struct Line* Front;
	struct Line* Back;
	double Data;
};
void init(struct Line** l)//получаем значение, взятое по адресу адреса
{
	*l = (struct Line*)malloc(sizeof(struct Line));
	(*l)->Front = NULL;
	(*l)->Back = NULL;
	(*l)->Data = 2147483648;
}
void clean(struct Line* l)
{
	struct Line* Temp = l;
	free(Temp->Back);
	do
	{
		Temp = Temp->Front;
		free(l);
		l = Temp;
	} while (l != NULL);
}
bool is_empty(struct Line* l)
{
	if (l == NULL)
		return 0;
	else
		return 1;
}
void print_inverse(struct Line* l)
{
	while (l->Front != NULL)
		l = l->Front;
	while (l != NULL)
	{
		printf("%.0lf ", l->Data);
		l = l->Back;
	}
	printf("\n");
}
struct Line* find(struct Line* l, int value)//найти элемент со значением
{
	struct Line* Temp = l;
	while (1)
	{
		if (Temp == NULL)
			return NULL;
		else
		{
			if ((Temp->Data) == value)
				return ((struct Line*)l);
		}
		Temp = Temp->Front;
	}
}
int push_front(struct Line** l, int value)
{
	struct Line* Temp = (struct Line*)malloc(sizeof(struct Line));//при этом здесь **l--это значение
	Temp->Data = value;
	Temp->Front = (*l);//то есть, в следующем элементе записан адрес начального эл-та списка
	Temp->Back = NULL;
	Temp->Front->Back = Temp;//указатель от прошлого первого элемента
	(*l) = Temp;
	return 0;
}
int insert_before(struct Line* l, int value)//вставка на нужное место(0--успех)
{
	if (l->Back != NULL)
	{
		struct Line* Temp = (struct Line*)malloc(sizeof(struct Line)), * Temp2;
		Temp->Back = l->Back;
		Temp->Front = l;
		Temp->Data = value;
		l->Back->Front = Temp;//меняем указатель с последующего элемента на вставляемый
		l->Back = Temp;
	}
	else
	{
		l->Back = (struct Line*)malloc(sizeof(struct Line));
		l->Back->Back = NULL;
		l->Back->Data = value;
		l->Back->Front = l;
	}
	return 0;
}
int push_back(struct Line* l, int value)//вставить в конец(0 при успехе)
{
	if (l->Data == 2147483648)
	{
		l->Data = value;
		return 0;
	}
	struct Line* Temp = (struct Line*)malloc(sizeof(struct Line));
	Temp = l;
	while (Temp->Front != NULL)
		Temp = Temp->Front;
	Temp->Front = (struct Line*)malloc(sizeof(struct Line));
	Temp->Front->Back = Temp;
	Temp = Temp->Front;
	Temp->Data = value;
	Temp->Front = NULL;
	return 0;
}
int remove_first(struct Line* l, int value)//удаление(надо сделать удаление 1-го)
{
	struct Line* Temp = l;
	if (l != NULL)
	{
		while (1)
		{
			if ((Temp->Front) == NULL)
				return 1;//не найдено
			if ((Temp->Front->Data) == value)
			{
				Temp = Temp->Front;
				if (Temp->Front != NULL)
				{
					Temp->Back->Front = Temp->Front;
					Temp->Front->Back = Temp->Back;
					free(Temp);
				}
				else
				{
					Temp->Back->Front = NULL;
					free(Temp);
				}
				return 0;
			}
			Temp = Temp->Front;
		}
	}
	else
		return 1;
}
int remove_last(struct Line* l, int value)
{
	struct Line* Temp = l, * TempSaving = NULL;
	if (l != NULL)
	{
		while (Temp->Front != NULL)
		{
			if ((Temp->Front->Data) == value)
				TempSaving = Temp->Front;
			Temp = Temp->Front;
		}
		if (TempSaving != NULL)
		{
			if (TempSaving->Front != NULL)
			{
				TempSaving->Back->Front = TempSaving->Front;
				TempSaving->Front->Back = TempSaving->Back;
				free(TempSaving);
			}
			else
			{
				TempSaving->Back->Front = NULL;
				free(TempSaving);
			}
			return 1;
		}
		return 0;
	}
	else
		return -1;
}
int insert_after(struct Line* l, int value)//вставка на нужное место(0--успех)
{
	if (l->Front != NULL)
	{
		struct Line* Temp = (struct Line*)malloc(sizeof(struct Line)), * Temp2;
		Temp->Front = l->Front;//делаем привязки от элемента к соседним тут
		Temp->Back = l;//и тут
		Temp->Data = value;
		l->Front->Back = Temp;//меняем указатель с последующего элемента на вставляемый
		l->Front = Temp;
	}
	else
	{
		l->Front = (struct Line*)malloc(sizeof(struct Line));
		l->Front->Front = NULL;
		l->Front->Data = value;
		l->Front->Back = l;
	}
	return 0;
}
void print(struct Line* l)
{
	while (l != NULL)
	{
		printf("%.0lf ", l->Data);
		l = l->Front;
	}
	printf("\n");
}


int main()
{
	struct Line* l, * Temp;
	int N, i;
	double a, b;
	scanf("%d", &N);//1 пункт
	init(&l);//2 пункт, передаём адрес адреса
	for (i = 0; i < N; i++)
	{
		scanf("%lf", &a);
		push_back(l, a);
	}
	print(l);//3 пункт
	for (i = 0; i < 3; i++)//4 пункт
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
	scanf("%lf", &a);//5 пункт
	push_back(l, a);
	print_inverse(l);//6 пункт
	scanf("%lf", &a);//7 пункт
	push_front(&l, a);
	print(l);//8 пункт
	scanf("%lf", &a);//9 пункт, здесь a--это j, номер в списке
	scanf("%lf", &b);//b--это x, само значение
	struct Line* el = (struct Line*)l;
	while (a != 1)
	{
		el = el->Front;
		a--;
	}
	insert_after(el, b);
	print_inverse(l);//10 пункт
	scanf("%lf", &a);//11, a=u
	scanf("%lf", &b);//b=y
	if (a == 1)
	{
		el = (struct Line*)malloc(sizeof(struct Line));
		el->Data = b;
		el->Back = NULL;
		el->Front = (struct Line*)l;
		l->Back = (struct Line*)el;
		l = l->Back;
	}
	else
	{
		el = (struct Line*)l;
		while (a != 1)
		{
			el = el->Front;
			a--;
		}
		insert_before(el, b);
	}
	print(l);//12 пункт
	scanf("%lf", &a);//13 пункт
	if (l->Data == a)
	{
		Temp = l->Front;
		free(l);
		l = Temp;
		l->Back = NULL;
	}
	else
		remove_first(l, a);
	print_inverse(l);//14 пункт
	scanf("%lf", &a);//15 пункт
	if ((remove_last(l, a) == 0) && (l->Data == a))
	{
		Temp = l->Front;
		free(l);
		l = Temp;
	}
	print(l);//16 пункт
	clean(l);//17 пункт
	return 1;
}
```


