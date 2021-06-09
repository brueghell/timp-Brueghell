### 1 Введение
Целью данной лабораторной работы является получение практических навыков по работе с бинарными деревьями. В частности нужно реализовать обходы деревьев.

Поставленные задачи представлены ниже:


1) Должны быть выполнены предыдущие работы


2) Прочитать про односвязные списки на СИ


3) Написать программу


4) Настроить pipeline


5) Написать отчет по работе в разметке Markdown (README.md)


6) Залить на gitlab и убедиться, что pipeline проходит успешно


7) Защитить работу у преподавателя

Реализовать 3 программы по обходам деревьев, функции, которых представлены в таблице 1.

Таблица 1 - Функции
| Номер | Задание |
| ------------- | ------------- |
|  1  | считать с входного потока 7 чисел и занести их в дерево;  |
|  2  | вывести все значения вершин дерева через пробел в порядке их посещения.  |


### 2 Ход работы
#### 2.1 Работа с кодом 
##### 2.1.1 Обход в ширину
Пусть мы находимся в корне дерева. Далее необходимо посетить всех наследников корня. Таким образом, нужно засунуть в контейнер сначала узел, затем его наследников, при этом узел далее должен быть обработан первым. То есть, элемент, который вошёл первым должен быть обработан первым. Это очередь, и в этом примере мы будем использовать готовую реализацию очереди с помощью двусвязного списка.

Используя IDE Visual Studio и CLion напишем код программы.

Для начала необходимо создать структуру tree, в которая будет представлять из себя дерево с левым и правым поддеревом.
Код представлен ниже:
```c
struct tree
{
	struct tree* right;
	struct tree* left;
	int data;
};
```
Функция, в которой реализована вставка значений в дерево представлена ниже:
```c
int insert(struct Tree* t, int value)
{
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

Результат работы программs представлен на рисунке 1.

![](https://sun9-43.userapi.com/impg/qaXuzsVIbkmG2PKoMtkiAXyqBDiT4_aO1-c_ew/Ckfygl230fM.jpg?size=677x343&quality=96&sign=7218436ceb3906639699a1a21d85b2f7&type=album)

Рисунок 1 — Результат работы программы первой программы.

##### 2.1.2 Прямой обход
Для того, чтобы совершить прямой обход дерева, нужно посетить корневой узел, далее пойти к левому поддереву и обойти его в прямой последовательности, после чего идти к правому поддереву и обойти его так же в прямой последовательности.

Так как последующие программы будут отличаться от первой только функцией вывода, именно она будет представлена. Функция print_direct представлена ниже:
```c
int print_direct(struct Tree* t)
{
	struct Tree* Temp[7];
	int i = 0;
	Temp[0] = t;
	printf("%d", (int)Temp[i]->Data);
	while (1)
	{
		while (1)//запись до конца
		{
			while ((Temp[i]->Left) != NULL)
			{
				Temp[i + 1] = Temp[i]->Left;
				i++;
				printf(" %d", (int)Temp[i]->Data);
			}
			if ((Temp[i]->Right) != NULL)
			{
				Temp[i + 1] = Temp[i]->Right;
				i++;
				printf(" %d", (int)Temp[i]->Data);
			}
			else
				break;
		}
		while ((i != 0) && ((Temp[i - 1]->Right) == Temp[i]))
			i--;
		if (i == 0)
			break;
		while (i != 0)
		{
			if ((Temp[i - 1]->Right) != NULL)
			{
				Temp[i] = Temp[i - 1]->Right;
				printf(" %d", (int)Temp[i]->Data);
				break;
			}
			else
			{
				i--;
				if (i == 0)
					return 0;
			}
		}
	}
	return 0;
}
```
Результат работы программs представлен на рисунке 2.

![](https://sun9-18.userapi.com/impg/Evh0F89JLAeGuEZMI-aQVDpLcwqgkcfTLQOiwg/5Lhw7S6s0co.jpg?size=677x345&quality=96&sign=885adfd94feb0b3cbc4d31aeaae8e26c&type=album)

Рисунок 2 — Результат работы второй программы.

##### 2.1.3 Обратный обход
Для того, чтобы совершить обратный обход дерева, нужно обойти левое поддерево обратным обходом (начинаем с самого левого листа), после чего нужно обойти правое поддерево обратным обходом, начиная с самого левого листа, далее просто обходим корневой узел.

Функция print_reverse представлена ниже:
```c
int print_reverse(struct Tree* t)//пробелы
{
	struct Tree* Temp[7];
	int i = 0;
	Temp[0] = t;
	while (1)
	{
		while (1)//запись до конца
		{
			while ((Temp[i]->Left) != NULL)
			{
				Temp[i + 1] = Temp[i]->Left;
				i++;
			}
			if ((Temp[i]->Right) != NULL)
			{
				Temp[i + 1] = Temp[i]->Right;
				i++;
			}
			else
				break;
		}
		while ((i != 0) && ((Temp[i - 1]->Right) == Temp[i]))//нужно сдвигаться вверх?
		{
			printf("%d ", (int)Temp[i]->Data);
			i--;
		}
		if (i == 0)
			break;
		while (i != 0)
		{
			if ((Temp[i - 1]->Right) != NULL)//нужно сдвигаться вправо?
			{
				printf("%d ", (int)Temp[i]->Data);
				Temp[i] = Temp[i - 1]->Right;
				break;
			}
			else
			{
				i--;
				printf("%d ", (int)Temp[i + 1]->Data);//выводим покинутый узел
				if (i == 0)
				{
					printf("%d", (int)Temp[i]->Data);
					return 0;
				}
			}
		}
	}
	printf("%d", (int)Temp[i]->Data);
	return 0;
}
```

Результат работы программs представлен на рисунке 3.

![](https://sun9-13.userapi.com/impg/rlIID5RJjj2s_vw5bpGCbLyrUDF9B6aK76nHkg/nNS9C90Duyg.jpg?size=678x343&quality=96&sign=a84002d895eb838eb1418891b9320809&type=album)

Рисунок 3 — Результат работы третьей программы.

#### 2.2 Работа с GitLab

Далее требуется настроить pipeline-тест. Для этого нужно добавить раскомментировать строки в  gitlab-ci.yml, как это представлено на рисунке 4.
![](https://sun9-41.userapi.com/impg/f2rhJx_kLqLwTBLkw3TwI3YUt1hW-AfQdY36kQ/h8WKloRn2Co.jpg?size=406x335&quality=96&sign=18be29834aab928a3349600615b6169e&type=album)

Рисунок 4 - Настройка gitlab-ci.yml

После настройки, нужно пройти pipeline-тест. Результат успешной проверки представлен на рисунке 5.

![](https://sun9-23.userapi.com/impg/H4OOvSjvkOz64X7ES3LePWwyMUl-eATDbK3N3A/3Z-IfnMYC6Y.jpg?size=241x239&quality=96&sign=3c8aa0a8e6199228decba7f123a94a2f&type=album)

Рисунок 5 - Успешно пройденный тест

### 3 Вывод

В результате выполнения данной лабораторной работы, были получены практические навыки работы с обходами бинарных деревьев и работы с динамической памятью. Были изучены такие обходы деревьев, как прямой, обратный и обход в ширину.

### Приложение A
### (обязательное)
Листининг кода  первой программы:
```c
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
struct Tree {
    struct Tree* Right;
    struct Tree* Left;
    double Data;
};
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
int insert(struct Tree* t, int value)
{
    if (t->Data == value)
        return 1;
    if (value > (t->Data)) {
        if ((t->Right) != NULL)
            return (insert(t->Right, value));
        else {
            t->Right = (struct Tree*)malloc(sizeof(struct Tree));
            t->Right->Right = NULL;
            t->Right->Left = NULL;
            t->Right->Data = value;
            return 0;
        }
    }
    else {
        if ((t->Left) != NULL)
            return (insert(t->Left, value));
        else {
            t->Left = (struct Tree*)malloc(sizeof(struct Tree));
            t->Left->Right = NULL;
            t->Left->Left = NULL;
            t->Left->Data = value;
            return 0;
        }
    }
}
void init(struct Tree** t, int value)
{
    *t = (struct Tree*)malloc(sizeof(struct Tree));
    (*t)->Right = NULL;
    (*t)->Left = NULL;
    (*t)->Data = value;
}
int print_width(struct Tree* t)
{
    struct Tree* Temp = t;
    int Rang = 0, i, j, k, sk, Spaces = 0;
    int* comb;
    Rang = deep(t);
    comb = (int*)malloc(sizeof(int));
    for (i = 0; i < Rang; i++) //обработка рангов
    {
        if (i != 0) //объявление-зануление
        {
            comb = (int*)realloc(comb, i * sizeof(int));
            for (j = 0; j < i; j++)
                comb[j] = 0;
        }
        j = 1;
        sk = i;
        while (sk != 0) //получение кол-ва элементов на уровне
        {
            j = j * 2;
            sk--;
        }
        while (j != 0) //проход для каждого элемента
        {
            k = 0;
            Temp = t;
            for (k = 0; k < i; k++) //проход до определённого узла
            {
                if (comb[k] == 0) {
                    if ((Temp->Left) != NULL)
                        Temp = Temp->Left;
                    else {
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
        
            if (k != -1) //если элемент есть вообще
            {
                if (Spaces == 1) {
                    printf(" ");
                    Spaces = 1;
                }
                printf("%d", (int)Temp->Data);
                Spaces = 1;
            }
            j--;
        } //конец ряда
    }
    return 0;
}
int main()
{
    struct Tree* t;
    double val;
    int i;
    scanf("%lf", &val);
    init(&t, val);
    for (i = 0; i < 6; i++) {
        scanf("%lf", &val);
        insert(t, val);
    }
    print_width(t);
    return 1;
}
```
### Приложение Б
### (обязательное)
Листининг кода  второй  программы:
```c
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
struct tree
{
	struct tree* right;
	struct tree* left;
	int data;
};


int main()
{
	struct tree* t;

	int value;

	int i;

	scanf("%d", &value);

	init(&t, value);

	for (i = 0; i < 6; i++)
	{
		scanf("%d", &value);
		insert(t, value);
	}

	print_direct(t);

	return 1;
}

int insert(struct tree* t, int value)
{
	if (t->data == value)
		return 1;
	if (value > (t->data))
	{
		if ((t->right) != NULL)
			return(insert(t->right, value));
		else
		{
			t->right = (struct tree*)malloc(sizeof(struct tree));

			t->right->right = NULL;

			t->right->left = NULL;

			t->right->data = value;

			return 0;
		}
	}
	else
	{
		if ((t->left) != NULL)

			return(insert(t->left, value));

		else

		{
			t->left = (struct tree*)malloc(sizeof(struct tree));

			t->left->right = NULL;

			t->left->left = NULL;

			t->left->data = value;

			return 0;
		}
	}
}
void init(struct tree** t, int value)
{
	*t = (struct tree*)malloc(sizeof(struct tree));

	(*t)->right = NULL;

	(*t)->left = NULL;

	(*t)->data = value;

}
int print_direct(struct tree* t)
{
	
	struct Tree* Temp[7];
	int i = 0;
	Temp[0] = t;
	printf("%d", (int)Temp[i]->Data);
	while (1)
	{
		while (1)//запись до конца
		{
			while ((Temp[i]->Left) != NULL)
			{
				Temp[i + 1] = Temp[i]->Left;
				i++;
				printf(" %d", (int)Temp[i]->Data);
			}
			if ((Temp[i]->Right) != NULL)
			{
				Temp[i + 1] = Temp[i]->Right;
				i++;
				printf(" %d", (int)Temp[i]->Data);
			}
			else
				break;
		}
		while ((i != 0) && ((Temp[i - 1]->Right) == Temp[i]))
			i--;
		if (i == 0)
			break;
		while (i != 0)
		{
			if ((Temp[i - 1]->Right) != NULL)
			{
				Temp[i] = Temp[i - 1]->Right;
				printf(" %d", (int)Temp[i]->Data);
				break;
			}
			else
			{
				i--;
				if (i == 0)
					return 0;
			}
		}
	}
	return 0;
}
}
return 0;
}
```
#### Приложение В
#### (обязательное)
Листининг кода  третьей  программы:
```c
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

struct tree {
    struct tree* right;

    struct tree* left;

    int data;
};

int print_reverse(struct tree* t);

void init(struct tree** t, int value);

int insert(struct tree* t, int value);

int insert(struct tree* t, int value)
{
    if (t->data == value)
        return 1;
    if (value > (t->data)) {
        if ((t->right) != NULL)
            return (insert(t->right, value));
        else {
            t->right = (struct tree*)malloc(sizeof(struct tree));
            t->right->right = NULL;
            t->right->left = NULL;
            t->right->data = value;
            return 0;
        }
    }
    else {
        if ((t->left) != NULL)
            return (insert(t->left, value));
        else {
            t->left = (struct tree*)malloc(sizeof(struct tree));
            t->left->right = NULL;
            t->left->left = NULL;
            t->left->data = value;
            return 0;
        }
    }
}

void init(struct tree** t, int value)
{
    *t = (struct tree*)malloc(sizeof(struct tree));

    (*t)->right = NULL;

    (*t)->left = NULL;

    (*t)->data = value;
}

int print_reverse(struct tree* t)
{
    if (t == NULL)
        return;
    print_reverse(t->left);
    print_reverse(t->right);
    printf("%d ", t->data);
}

int main()
{
    struct tree* t;

    int value;

    int i;

    scanf("%d", &value);

    init(&t, value);

    for (i = 0; i < 6; i++) {
        scanf("%d", &value);
        insert(t, value);
    }

    print_reverse(t);

    return 1;
}

```
