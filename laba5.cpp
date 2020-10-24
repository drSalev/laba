//9. Дана действительная квадратная матрица порядка 2n. Разделив матрицу на равные 4 сектора, получить 
// новую квадратную матрицу, переставляя эти сектора по часовой стрелке.
#define _CRT_SECURE_NO_WARNINGS
#define kl 6
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	int mt[kl][kl], s1[kl / 2][kl / 2], s2[kl / 2][kl / 2], s3[kl / 2][kl / 2], s4[kl / 2][kl / 2];
	printf(" Ввод массива:\n");
	for (int i = 0; i < kl; i++) // Начало ввода массива с проверкой
	{
		for (int j = 0; j < kl; j++)
		{
			while (1)
			{
				printf(" Введите a[%d][%d]= ", i + 1, j + 1);
				if (scanf("%d", &mt[i][j]))
				{
					break;
				}
				else
				{
					printf("  Ошибка ввода!");
					rewind(stdin);
				}
			}
		}
	} // Конец ввода ммассива
	getchar(); getchar(); system("CLS");
	printf("  Ваш массив:\n");   // Начало вывода массива(для удобного сравнения)
	for (int i = 0; i < kl; i++)
	{
		for (int j = 0; j < kl; j++)
		{
			printf(" [%d]", mt[i][j]);
		}
		printf("\n");
	} // Конец вывода массива
	printf("\n");
	for (int i = 0; i < (kl / 2); i++) // Начало радробления массива на сектора. Сектор 1.
	{
		for (int j = 0; j < (kl / 2); j++)
		{
			s1[i][j] = mt[i][j];
		}
	}
	for (int i = 0; i < (kl / 2); i++) // Сектор 2.
	{
		for (int j = (kl / 2), k = 0; j < kl && k < (kl / 2); j++ && k++)
		{
			s2[i][k] = mt[i][j];
		}
	}
	for (int i = (kl / 2), o = 0; i < kl && o < (kl / 2); i++ && o++) // Сектор 3.
	{
		for (int j = (kl / 2), k = 0; j < kl && k < (kl / 2); j++ && k++)
		{
			s3[o][k] = mt[i][j];
		}
	}
	for (int i = (kl / 2), o = 0; i < kl && o < (kl / 2); i++ && o++) // Сектор 4.
	{
		for (int j = 0; j < (kl / 2); j++)
		{
			s4[o][j] = mt[i][j];
		}
	}   // Конец раздробления на раздробления на сектора.                                                             
	for (int i = 0; i < (kl / 2); i++) // Начало изменения по секторам
	{
		for (int j = 0; j < (kl / 2); j++)
		{
			mt[i][j] = s4[i][j];
		}
	}
	for (int i = 0; i < (kl / 2); i++) 
	{
		for (int j = (kl / 2), k = 0; j < kl && k < (kl / 2); j++ && k++)
		{
			mt[i][j] = s1[i][k];
		}
	}
	for (int i = (kl / 2), o = 0; i < kl && o < (kl / 2); i++ && o++) 
	{
		for (int j = (kl / 2), k = 0; j < kl && k < (kl / 2); j++ && k++)
		{
			mt[i][j] = s2[o][k];
		}
	}
	for (int i = (kl / 2), o = 0; i < kl && o < (kl / 2); i++ && o++) 
	{
		for (int j = 0; j < (kl / 2); j++)
		{
			mt[i][j] = s3[o][j];
		}
	} // Конец изменения массива
	printf("  Новый массив:\n");   // Начало вывода измененного массива
	for (int i = 0; i < kl; i++)
	{
		for (int j = 0; j < kl; j++)
		{
			printf(" [%d]", mt[i][j]);
		}
		printf("\n");
	} // Конец вывода
	getchar(); getchar();
	return 0;
}
