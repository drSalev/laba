﻿//7. В действительной квадратной матрице порядка n найти наибольший по модулю элемент.
//Получить квадратную матрицу порядка n - 1 путем выбрасывания из исходной матрицы какой - 
//нибудь строки и столбца, на пересечении которых расположен элемент с найденным значением.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Russian"); // Русификация
	int n, **mt1, x, i1, j1;
	printf("  Введите размерность массива: ");
	scanf("%d", &n); 
	mt1 = (int**)malloc(n * sizeof(int*)); // Начало создания динамичского массива 
	for (int i = 0; i < n; i++)
	{
		mt1[i] = (int*)malloc(n * sizeof(int));
	} // конец создания
	for (int i = 0; i < n; i++) // Начало заполнения массива с проверкой на ввод
	{
		for (int j = 0; j < n; j++)
		{
			printf(" Введите a[%d][%d]= ", i + 1, j + 1);
			while (1)
			{
				if (scanf("%d", &mt1[i][j]))
				{
					break;
				}
				else
				{
					printf(" Ошибка ввода!\n");
					rewind(stdin); //очистка буфера ввода
				}
			}
		}
	} // Конец заполнения массива
	getchar(); getchar();
	system("CLS"); // Очистка консоли
	printf(" Ваша матрица:"); // Начало вывода массива
	for (int i = 0; i < n; i++)
	{
		printf("\n");
		for (int j = 0; j < n; j++)
		{
			printf("[%d] ", mt1[i][j]);
		}
	} // Конец вывода массива
	x = mt1[0][0]; i1 = 0; j1 = 0; // Начало нахождения наибольшего элемента
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++)
		{
			if (x < mt1[i][j])
			{
				x = mt1[i][j];
				i1 = i;
				j1 = j;
			}
		}
	} // Конец нахождения наибольшего элемента а[i][j]
	for (int i = 0; i < n; i++) // Начало удаления j-ого столбца 
	{
		for (int j = j1; j < n; j++)
		{
			mt1[i][j] = mt1[i][j + 1];
		}
	} // Конец удаления j-ого столбца
	for (int i = i1; i < n - 1; i++) // Начало удаления i-ой строки
	{
		mt1[i] = mt1[i + 1];
	} // Конец удаления i-ой строки
	printf("\n Новая матрица:"); // Начало вывода измененной матрицы
	for (int i = 0; i < n-1; i++)
	{
		printf("\n");
		for (int j = 0; j < n-1; j++)
		{
			printf("[%d] ", mt1[i][j]);
		}
	} // Конец вывода измененной строки
	for (i = 0; i < n; i++) 
	{
                free(mt1[i]);
        }
        free(mt1);
	getchar(); getchar();
	return 0;
}
