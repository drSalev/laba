﻿#define _CRT_SECURE_NO_WARNINGS // для корректной работы scanf()
#include <stdio.h>
#include <locale.h>
#define kl 10 // размерность массива (глобальная константа)

//9. Рассортировать одномерный массив по возрастанию(убыванию) элементов. 
int main()
{
    setlocale(LC_ALL, "Russian"); // русификация
    int a[kl]; // объявление массива
    
    printf("  Ввод массива, состоящего из %i элементов:\n", kl);
    for (int i = 0; i < kl; i++)  // ввод массива
    {
        while (1) //Проверка на ввод числа
        {
            printf(" Введите a[%d] = ", i);
            if (scanf("%d", &a[i]))
            {
                break;
            }
            else
            {
                printf(" Ошибка ввода!\n");
                rewind(stdin); // чистка буфера ввода
            }
        }
    }
    printf("  Ваш начальный массив:\n");
    for (int i = 0; i < kl; i++) // вывод начального массива
    {
        printf("%d ", a[i]);
    }
    printf("\n");    
    char opr;  // объявление символа вля функции выбора
    printf("  Для сортировки по возрастанию введите '<'.\n Для сортировки по убыванию введите '>'.\n ");
    rewind(stdin);
    scanf("%c", &opr);
    switch (opr) // функция выбора
    {
    case '<': // сортировка по возрастанию
        for (int i = 0; i < kl - 1; i++) // метод пузырька (возрастание)
        {
            for (int j = 0; j < kl - i - 1; j++) // сравниваем два соседних элемента. 
            {
                if (a[j] > a[j + 1]) // если они идут в неправильном порядке, то меняем их местами.
                {
                    int x = a[j];    // ввод вспомогательной переменной для смены мест между собой
                    a[j] = a[j + 1];
                    a[j + 1] = x;
                }
            }

        }
        break;
    case '>': // сортировка по убыванию
        for (int i = 0; i < kl - 1; i++) //метод пузырька (убывание)
        {
            for (int j = 0; j < kl - i - 1; j++) // сравниваем два соседних элемента. 
            {
                if (a[j] < a[j + 1]) // если они идут в неправильном порядке, то меняем их местами.
                {
                    int x = a[j];    // ввод вспомогательной переменной для смены мест между собой
                    a[j] = a[j + 1];
                    a[j + 1] = x;
                }
            }

        }
        break;
    default:
        printf("\n Ошибка ввода!");
        getchar(); getchar();
        return 0;
    }
    printf("  Рассортированный массив:\n");
    for (int i = 0; i < kl; i++) // вывод измененного массива
    {
        printf("%d ", a[i]);
    }
    getchar(); getchar();
    return 0;
}