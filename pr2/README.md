# Отчет по практической работе №2
### 1 Введение
Целью данной работы является ознакомление и получение первичных навыков взаимодействия с однопроходными алгоритмами.

Шаги выполнения лабораторной работы представлены ниже:

1.Должна быть выполнена 1 практическая работа

2.Написать программы в соответствии с вариантом

3.Настроить pipeline

4.Составить блок-схемы программ

5.Написать отчет по работе в разметке Markdown (README.md)

6.Залить на gitlab и убедиться, что pipeline проходит успешно

7.Защитить работу у преподавателя

Задания на вторую практическую работу представлены в таблице 1.

Таблица 1 - Задания
| Номер | Задание |
| ------------- | ------------- |
|  5  | Найти среднее арифметическое n-чисел, введенных с клавиатуры.  |
| 15  | Найти сумму четных кубов n-чисел, введенных с клавиатуры. |

### 2 Ход работы
#### 2.1 Работа с кодом
Используя онлайн компилятор и CLion напишем коды программ.

Код для программы №1 выглядит следующим образом:
```с
#include<stdio.h>

int main()
{
int n,a,i;
double sum=0;
(void)scanf("%d", &n);
for (i=0;i<n;i++)
{
    (void)scanf("%d",&a);
    sum+=a;
}
printf("%lf",(double)sum/n);
return 0;
}
```
Результат работы программы №1 представлен на рисунке 1.

![](https://sun9-18.userapi.com/impf/5L1FTdM0pxJF9AMado5taJS8tNirnGuI6WYIig/dR3ofBqPSNI.jpg?size=403x201&quality=96&sign=99843129cf226e47ce74c0764a9a643a&type=album)

Рисунок 1 — Результат работы программы №1

Изначально в консоль в первую строку вводится количество чисел (в нашем случае - "5"). Далее мы вводим эти числа, они сумируются, делятся и впоследствии выводится среднее арифметическое. 

Код для программы №2 выглядит следующим образом:
```с
#include <math.h>
#include <stdio.h>
int main()
{
    int i;
    int n = 0;
    double sum = 0;
    int x = 0;
    (void)scanf("%d", &n);
    for( i=1; i<=n; i++)
    {
        (void)scanf("%d", &x);
        if (i%2 == 0)
        {
            x = x*x*x;
            sum = sum + x;
        }
    }
    printf("%lf", sum);
    return 0;
}
```
Изначально в консоль в первую строку вводится количество чисел (в нашем случае - "5"). Далее мы вводим эти числа, программа находит из них четные, далее они возводятся в куб и суммируются.

Результат работы программы №2 представлен на рисунке 2.

Рисунок 2 — Результат работы программы №2

![](https://sun9-71.userapi.com/impf/yXl-x0apVm2BLTA9bI87sqTg0A4Bb6XEOShj_Q/9M_xhpw_uj0.jpg?size=496x201&quality=96&sign=86f776076aba744a8b27d48acd665a94&type=album)


#### 3.2 Работа с GitLab

Внесем последние в локальный проект и перешлем его в GitLab (commit and push).
Результаты проверки представлены на рисунке 3.

Рисунок 3 — Результаты pipeline-проверки

![](https://sun9-64.userapi.com/impf/32Ltvmvni2s7MUTP5hY5KBzU7RiFm3r5grzyVw/dsECkgb7CWg.jpg?size=483x378&quality=96&sign=89a2eb86f06fe0cd5710c432f61fb1aa&type=album)

#### 3.3 Работа с блок-схемами
Создадим блок-схемы для программы №5 и №15.



![](https://sun9-74.userapi.com/impf/DltD5BB9IRWgLbr5Y8s2aqDk3G_u8eeV0MR7rw/_uK26j3_5GM.jpg?size=161x807&quality=96&sign=c8a137f2d3f6c18b8b0551f03b964653&type=album)

Рисунок 4 — Блок схема для программы №5


![](https://sun9-40.userapi.com/impf/qYIxfz9H6nT9x6TcFLPJjzjIEL3vRNWlOOahKQ/LzME0snymQE.jpg?size=198x932&quality=96&sign=678bc550f38bbc912362763c35c9c45c&type=album)

Рисунок 5 — Блок схема для программы №15
### 4 Заключение
В ходе выполнения практической работы, были изучены основы однопроходных алгоритмов, а также успешно разработаны программы, заданные вариантом.

