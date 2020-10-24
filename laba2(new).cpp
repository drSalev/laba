#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() {
	setlocale(LC_ALL, "Russian");
	double Z, y1, y2, y3, x;
	while (1) {                                                   // Ввод и проверка на ввод числа 
		printf(" Введите число.\nx = ");
		if (scanf_s("%lf", &x)) {
			break;
		}
		else {
			printf("\n Это не число...\n");
			rewind(stdin);
		}
	}
	y1 = x - 0.5;                                                 // Расчеты
	y2 = 3 * powf(x, 2) - 0.1;
	y3 = 0.2 * powf(x, 2) - 0.3 * x;
	Z = 2 * powf(y1, 3) - 1.5 * y3 + 0.7 * y2;
	printf("\nЗначение функции равно %lf.\n\n\n\n", Z);            // Вывод значения функции
	return 0;
}