#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <windows.h>

struct data 
{
	int serial_number;
	struct FIO
	{
		char surname[60];
		char name[60];
		char partonymic[60];
	} fio;
	union MED 
	{
		int growth[2];
		int weight;
	} med;
};

void Transformation(char **cmdchar, data *array, int n);
void Input(data* array, int i);
void Output(data* array, int i);
int Delete(struct data* pok, int n, int flug);
void Sorting(struct data* pok, int n, int flug, int type);
void Change(struct data* pok, int n, int flug);
void Search(struct data* pok, int n, int flug);
int* FSearchFam(struct data* pok, int n, int flug);
int* FSearchIm(struct data* pok, int n, int flug);
int* FSearchOt(struct data* pok, int n, int flug);
int* FSearchAdd(struct data* pok, int n, int flug);
int* FSearchNum(struct data* pok, int n, int flug);
int* FSearchCRC(struct data* pok, int n, int flug);
int* FullSearch(struct data* pok, int n, int flug);



int main(int argc, char* argv[])
{
	if (argc == 1)
		return 0;
	int i, x, a, d = 0, n = argc - 1;
	data* students;
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	students = (data*)calloc(argc, sizeof(data));
	Transformation(argv, students, argc);
	for (i = 0; i < argc - 1; i++)
		Output(students, i);
	do
	{
		printf(" Для изменения данных о студенте введите 1.\n Для удаления студента введите 2.\n Для поиска студента введите 3.\n Для сортировки студентов введите 4.\n Для просмотра студентов введите 5.\n Для выхода введите 6.\n ");
		rewind(stdin);
		scanf_s(" %d", &x);
		system("cls");
		a = 0;
		switch (x)
		{
		case 1:
			do
			{
				printf(" По какому критерию Вы хотели бы найти данные о студенте для изменения?\n 1. По фамилии.\n 2. По имени.\n 3. По отчеству.\n 4. По всем параметрам(ФИО). \n 5. Вернуться назад.\n ");
				rewind(stdin);
				scanf_s(" %d", &x);
				system("cls");
				switch (x)
				{
				case 1:
					Change(students, n, 1);
					break;
				case 2:
					Change(students, n, 2);
					break;
				case 3:
					Change(students, n, 3);
					break;
				case 4:
					Change(students, n, 4);
					break;
				case 5:
					a++;
					break;
				}
			} while (!a);
			break;
		case 2:
			do
			{
				printf(" По какому критерию Вы хотели бы найти данные о студенте для удаления?\n 1. По фамилии.\n 2. По имени.\n 3. По отчеству.\n 4. По всем параметрам(ФИО).\n 5. Вернуться назад.\n ");
				rewind(stdin);
				scanf_s(" %d", &x);
				system("cls");
				switch (x)
				{
				case 1:
					n = Delete(students, n, 1);
					break;
				case 2:
					n = Delete(students, n, 2);
					break;
				case 3:
					n = Delete(students, n, 3);
					break;
				case 4:
					n = Delete(students, n, 4);
					break;
				case 5:
					a++;
					break;
				}
			} while (!a);
			break;
		case 3:
			do
			{
				printf(" Как Вы бы хотели осуществить поиск?\n 1. По частичному совпадению.\n 2. По одному заданному параметру.\n 3. По всем заданным параметрам(ФИО).\n 4. Вернуться назад.\n ");
				rewind(stdin);
				scanf_s(" %d", &x);
				system("cls");
				switch (x)
				{
				case 1:
					printf(" По какому критерию Вы хотели бы найти данные о студенте?\n 1. По фамилии.\n 2. По имени.\n 3. По отчеству.\n 4. Вернуться назад.\n ");
					rewind(stdin);
					scanf_s(" %d", &x);
					system("cls");
					do
					{
						switch (x)
						{
						case 1:
							Search(students, n, 1);
							break;
						case 2:
							Search(students, n, 2);
							break;
						case 3:
							Search(students, n, 3);
							break;
						case 4:
							a++;
							break;
						}
					} while (!a);
					break;
				case 2:
					printf(" По какому критерию Вы хотели бы найти данные о студенте?\n 1. По фамилии.\n 2. По имени.\n 3. По отчеству.\n 4. Вернуться назад.\n ");
					rewind(stdin);
					scanf_s(" %d", &x);
					system("cls");
					do
					{
						switch (x)
						{
						case 1:
							FSearchFam(students, n, 0);
							break;
						case 2:
							FSearchIm(students, n, 0);
							break;
						case 3:
							FSearchOt(students, n, 0);
							break;
						case 4:
							a++;
							break;
						}
					} while (!a);
					break;
				case 3:
					FullSearch(students, n, 0);
					break;
				}
				break;
			} while (!a);
			break;
		case 4:
			do
			{
				printf(" Как бы Вы хотели сортировать даннные?\n 1. По возрастанию.\n 2. По убыванию.\n 3. Вернуться назад.\n ");
				rewind(stdin);
				scanf_s(" %d", &x);
				system("cls");
				switch (x)
				{
				case 1:
					do
					{
						printf(" По какому критерию Вы хотели бы сортировать данные о студентах?\n 1. По фамилии.\n 2. По имени.\n 3. По отчеству.\n 4. Вернуться назад.\n ");
						rewind(stdin);
						scanf_s(" %d", &x);
						system("cls");
						switch (x)
						{
						case 1:
							Sorting(students, n, 1, 0);
							break;
						case 2:
							Sorting(students, n, 2, 0);
							break;
						case 3:
							Sorting(students, n, 3, 0);
							break;
						case 4:
							a++;
							break;
						}
					} while (!a);
					break;
				case 2:
					do
					{
						printf(" По какому критерию Вы хотели бы сортировать данные о студентах?\n 1. По фамилии.\n 2. По имени.\n 3. По отчеству.\n 4. Вернуться назад.\n ");
						rewind(stdin);
						scanf_s(" %d", &x);
						system("cls");
						switch (x)
						{
						case 1:
							Sorting(students, n, 1, 1);
							break;
						case 2:
							Sorting(students, n, 2, 1);
							break;
						case 3:
							Sorting(students, n, 3, 1);
							break;
						case 4:
							a++;
							break;
						}
					} while (!a);
					break;
				case 3:
					a++;
					break;
				}
			} while (!a);
			break;
		case 5:
			for (int i = 0; i < n; i++)
				Output(students, i);
			break;
		case 6:
			d++;
			break;
		}
	} while (!d);
	return 0;
}
void Transformation(char** cmdchar, data* array, int n)
{
	int i, j, k, b, a, c, S, E;
	char word[60];
	for (i = 1; i < n; i++)
	{
		array[i - 1].serial_number = i - 1;
		j = b = k = c = S = E = 0;
		do
		{
			while (cmdchar[i][j] == ' ')
			{
				if (cmdchar[i][j + 1] != ' ')
				{
					S = j + 1;
					c++;
				}
				j++;
			}
			while (cmdchar[i][j] != ' ' && k < 5)
			{
				if (!c)
				{
					S = j;
					c++;
				}
				if (cmdchar[i][j + 1] == ' ' || cmdchar[i][j + 1] == '\0')
				{
					E = j + 1;
					k++;
				}
				j++;
			}
			a = -1;
			switch (k)
			{
			case 1:
				for (b = S; b < E; b++)
				{
					a++;
					word[a] = cmdchar[i][b];
				}
				word[a + 1] = '\0';
				strcpy(array[i - 1].fio.surname, word);
				break;
			case 2:
				for (b = S; b < E; b++)
				{
					a++;
					word[a] = cmdchar[i][b];
				}
				word[a + 1] = '\0';
				strcpy(array[i - 1].fio.name, word);
				break;
			case 3:
				for (b = S; b < E; b++)
				{
					a++;
					word[a] = cmdchar[i][b];
				}
				word[a + 1] = '\0';
				strcpy(array[i - 1].fio.partonymic, word);
				break;
			case 4:
				for (b = S; b < E; b++)
				{
					a++;
					word[a] = cmdchar[i][b];
				}
				word[a + 1] = '\0';
				array[i - 1].med.growth[1] = atoi(word);
				break;
			case 5:
				for (b = S; b < E; b++)
				{
					a++;
					word[a] = cmdchar[i][b];
				}
				word[a + 1] = '\0';
				array[i - 1].med.weight = atoi(word);
				break;
			}
		} while (cmdchar[i][j] != '\0');
	}
}
void Input(struct data* array, int i)
{
	array[i].serial_number = i;
	int a = 0;
	do {
		if (a)
			printf(" Введите корректно фамилию студента.\n");
		printf(" Фамилия %d студента: ", i + 1);
		rewind(stdin);
		gets_s(array[i].fio.surname);
		a++;
	} while (array[i].fio.surname[0] == '\0');
	a = 0;
	do {
		if (a)
			printf(" Введите корректно имя студента.\n");
		printf(" Имя %d студента: ", i + 1);
		rewind(stdin);
		gets_s(array[i].fio.name);
		a++;
	} while (array[i].fio.name[0] == '\0');
	a = 0;
	do {
		if (a)
			printf(" Введите корректно отчество студента.\n");
		printf(" Отчество %d студента: ", i + 1);
		rewind(stdin);
		gets_s(array[i].fio.partonymic);
		a++;
	} while (array[i].fio.partonymic[0] == '\0');
	
	while (1) {
		printf(" Введите рост %d студента: ", i + 1);
		if (scanf_s(" %d", &array[i].med.growth[1])) {
			break;
		}
		else {
			printf(" Введите число.\n ");
			rewind(stdin);
		}
	}

	while (1) {
		printf(" Введите вес %d студента: ", i + 1);
		if (scanf_s(" %d", &array[i].med.weight)) {
			break;
		}
		else {
			printf(" Введите число.\n ");
			rewind(stdin);
		}
	}
	printf("\n");
}
void Output(struct data* array, int i)
{
	printf(" Фамилия %d студента ", i + 1);
	puts(array[i].fio.surname);
	printf(" Имя %d студента ", i + 1);
	puts(array[i].fio.name);
	printf(" Отчество %i студента ", i + 1);
	puts(array[i].fio.partonymic);
	printf(" Рост %d студента: %d\n", i + 1, array[i].med.growth[1]);
	printf(" Вес %d студента: %d\n", i + 1, array[i].med.weight);
	printf("\n");
}
int Delete(struct data* array, int n, int flug)
{
	int* a; int e = n, r = 0, k = 0;
	a = (int*)calloc(1, sizeof(int));
	switch (flug)
	{
	case 1:
		a = FSearchFam(array, n, 1);
		break;
	case 2:
		a = FSearchIm(array, n, 1);
		break;
	case 3:
		a = FSearchOt(array, n, 1);
		break;
	case 4:
		a = FullSearch(array, n, 1);
		break;
	}
	for (int i = n - 1; i >= 0; i--)
	{
		if (a[i] >= 0)
		{
			for (int j = a[i]; j < n; j++)
			{
				strcpy(array[j].fio.surname, array[j + 1].fio.surname);
				strcpy(array[j].fio.name, array[j + 1].fio.name);
				strcpy(array[j].fio.partonymic, array[j + 1].fio.partonymic);
				array[j].med.growth[1] = array[j + 1].med.growth[1];
				array[j].med.weight = array[j + 1].med.weight;
				
			}
			e--;
		}
	}
	return e;
}
void Sorting(struct data* array, int n, int flug, int type)
{
	data c;
	if(!type)
	for (int i = n - 1; i > 0; i--)
		for (int j = 0; j < i; j++)
		{
			switch (flug)
			{
			case 1:
				if (strcmp(array[j].fio.surname, array[j + 1].fio.surname) > 0)
				{
					c = array[j];
					array[j] = array[j + 1];
					array[j + 1] = c;
				}
				break;
			case 2:
				if (strcmp(array[j].fio.name, array[j + 1].fio.name) > 0)
				{
					c = array[j];
					array[j] = array[j + 1];
					array[j + 1] = c;
				}
				break;
			case 3:
				if (strcmp(array[j].fio.partonymic, array[j + 1].fio.partonymic) > 0)
				{
					c = array[j];
					array[j] = array[j + 1];
					array[j + 1] = c;
				}
				break;
			}
		}
	else
		for (int i = n - 1; i > 0; i--)
			for (int j = 0; j < i; j++)
			{
				switch (flug)
				{
				case 1:
					if (strcmp(array[j].fio.surname, array[j + 1].fio.surname) < 0)
					{
						c = array[j];
						array[j] = array[j + 1];
						array[j + 1] = c;
					}
					break;
				case 2:
					if (strcmp(array[j].fio.name, array[j + 1].fio.name) < 0)
					{
						c = array[j];
						array[j] = array[j + 1];
						array[j + 1] = c;
					}
					break;
				case 3:
					if (strcmp(array[j].fio.partonymic, array[j + 1].fio.partonymic) < 0)
					{
						c = array[j];
						array[j] = array[j + 1];
						array[j + 1] = c;
					}
					break;
				}
			}
	for (int i = 0; i < n; i++)
		array[i].serial_number = i;
}
void Change(struct data* array, int n, int flug)
{
	int* a; int e, r = 0;
	a = (int*)calloc(1, sizeof(int));
	switch (flug)
	{
	case 1:
		a = FSearchFam(array, n, 1);
		break;
	case 2:
		a = FSearchIm(array, n, 1);
		break;
	case 3:
		a = FSearchOt(array, n, 1);
		break;
	case 4:
		a = FullSearch(array, n, 1);
		break;
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= 0)
		{
			Input(array, a[i]);
			r++;
		}
		if (!r)
			printf("\n Ничего не найдено.\n");
	}
}
void Search(struct data* array, int n, int flug)
{
	int i = 0, j = 0, c = 0, dlS, dlA;
	char* s;
	switch (flug)
	{
	case 1:
		printf(" Введите букву или слово для поиска: \n ");
		rewind(stdin);
		s = (char*)malloc(1);
		while ((s[j++] = getchar()) != '\n')
			s = (char*)realloc(s, j + 1);
		s[j - 1] = '\0';
		dlS = j - 1;
		for (int a = 0; a < n; a++)
		{
			i = j = 0;
			for (dlA = 0; array[a].fio.surname[dlA]; dlA++);
			while (i < dlA)
			{
				if (j < dlS)
				{
					if (array[a].fio.surname[i] == s[j])
					{
						i++;
						j++;
					}
					else
					{
						j = 0;
						i++;
					}
				}
				if (j == dlS)
				{
					c++;
					Output(array, a);
					break;
				}
			}
			if (c == 0)
			{
				puts("\n Ничего не найдено.\n");
				return;
			}
		}
		free(s);
		break;
	case 2:
		printf(" Введите букву или слово для поиска: \n ");
		rewind(stdin);
		s = (char*)malloc(1);
		while ((s[j++] = getchar()) != '\n')
			s = (char*)realloc(s, j + 1);
		s[j - 1] = '\0';
		dlS = j - 1;
		for (int a = 0; a < n; a++)
		{
			i = j = 0;
			for (dlA = 0; array[a].fio.name[dlA]; dlA++);
			while (i < dlA)
			{
				if (j < dlS)
				{
					if (array[a].fio.name[i] == s[j])
					{
						i++;
						j++;
					}
					else
					{
						j = 0;
						i++;
					}
				}
				if (j == dlS)
				{
					c++;
					Output(array, a);
					break;
				}
			}
			if (c == 0)
			{
				puts("\n Ничего не найдено.\n");
				return;
			}
		}
		free(s);
		break;
	case 3:
		printf(" Введите букву или слово для поиска: \n ");
		rewind(stdin);
		s = (char*)malloc(1);
		while ((s[j++] = getchar()) != '\n')
			s = (char*)realloc(s, j + 1);
		s[j - 1] = '\0';
		dlS = j - 1;
		for (int a = 0; a < n; a++)
		{
			i = j = 0;
			for (dlA = 0; array[a].fio.partonymic[dlA]; dlA++);
			while (i < dlA)
			{
				if (j < dlS)
				{
					if (array[a].fio.partonymic[i] == s[j])
					{
						i++;
						j++;
					}
					else
					{
						j = 0;
						i++;
					}
				}
				if (j == dlS)
				{
					c++;
					Output(array, a);
					break;
				}
			}
			if (c == 0)
			{
				puts("\n Ничего не найдено.\n");
				return;
			}
		}
		free(s);
		break;
	}
}
int* FSearchFam(struct data* array, int n, int flug)
{
	int i = 0, j = 0, c = 0, y = 0, dlS, dlA;
	char* s; int* inf;
	printf(" Введите фамилию студента: \n ");
	rewind(stdin);
	s = (char*)malloc(1);
	while ((s[j++] = getchar()) != '\n')
		s = (char*)realloc(s, j + 1);
	s[j - 1] = '\0';
	dlS = j - 1;
	inf = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
		inf[i] = -1;
	for (int a = 0; a < n; a++)
	{
		i = j = y = 0;
		for (dlA = 0; array[a].fio.surname[dlA]; dlA++);
		while (i < dlA)
		{
			if (j == dlS)
			{
				break;
			}
			if (j < dlS)
			{
				if (array[a].fio.surname[i] == s[j])
				{
					i++;
					j++;
					y++;
				}
				else
				{
					break;
				}
			}
		}
		if (j == dlA && y && s[j] == '\0')
		{
			inf[c] = array[a].serial_number;
			c++;
		}
	}
	free(s);
	if (c == 0 && flug == 0)
	{
		puts("\n Ничего не найдено.\n");
		return 0;
	}
	if (flug == 0)
	{
		for (int i = 0; i < n && inf[i] >= 0; i++)
			Output(array, inf[i]);
		return 0;
	}
	if (flug == 1)
	{
		return inf;
	}
}
int* FSearchIm(struct data* array, int n, int flug)
{
	int i = 0, j = 0, c = 0, y = 0, dlS, dlA;
	char* s; int* inf;
	printf(" Введите имя студента: \n ");
	rewind(stdin);
	s = (char*)malloc(1);
	while ((s[j++] = getchar()) != '\n')
		s = (char*)realloc(s, j + 1);
	s[j - 1] = '\0';
	dlS = j - 1;
	inf = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
		inf[i] = -1;
	for (int a = 0; a < n; a++)
	{
		i = j = y = 0;
		for (dlA = 0; array[a].fio.name[dlA]; dlA++);
		while (i < dlA)
		{
			if (j == dlS)
			{
				break;
			}
			if (j < dlS)
			{
				if (array[a].fio.name[i] == s[j])
				{
					i++;
					j++;
					y++;
				}
				else
				{
					break;
				}
			}
		}
		if (j == dlA && y && s[j] == '\0')
		{
			inf[c] = array[a].serial_number;
			c++;
		}
	}
	free(s);
	if (c == 0 && flug == 0)
	{
		puts("\n Ничего не найдено.\n");
		return 0;
	}
	if (flug == 0)
	{
		for (int i = 0; i < n && inf[i] >= 0; i++)
			Output(array, inf[i]);
		return 0;
	}
	if (flug == 1)
	{
		return inf;
	}
}
int* FSearchOt(struct data* array, int n, int flug)
{
	int i = 0, j = 0, c = 0, y = 0, dlS, dlA;
	char* s; int* inf;
	printf(" Введите отчество покупателя: \n ");
	rewind(stdin);
	s = (char*)malloc(1);
	while ((s[j++] = getchar()) != '\n')
		s = (char*)realloc(s, j + 1);
	s[j - 1] = '\0';
	dlS = j - 1;
	inf = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
		inf[i] = -1;
	for (int a = 0; a < n; a++)
	{
		i = j = y = 0;
		for (dlA = 0; array[a].fio.partonymic[dlA]; dlA++);
		while (i < dlA)
		{
			if (j == dlS)
			{
				break;
			}
			if (j < dlS)
			{
				if (array[a].fio.partonymic[i] == s[j])
				{
					i++;
					j++;
					y++;
				}
				else
				{
					break;
				}
			}
		}
		if (j == dlA && y && s[j] == '\0')
		{
			inf[c] = array[a].serial_number;
			c++;
		}
	}
	free(s);
	if (c == 0 && flug == 0)
	{
		puts("\n Ничего не найдено.\n");
		return 0;
	}
	if (flug == 0)
	{
		for (int i = 0; i < n && inf[i] >= 0; i++)
			Output(array, inf[i]);
		return 0;
	}
	if (flug == 1)
	{
		return inf;
	}
}
int* FullSearch(struct data* array, int n, int flug)
{
	int* a; int* b;
	int x = 1, s = 0, c = 0;
	a = (int*)calloc(1, sizeof(int));
	b = (int*)calloc(1, sizeof(int));
	a = FSearchFam(array, n, 1);
	do
	{
		switch (x)
		{
		case 1:
			b = FSearchIm(array, n, 1);
			x++;
			break;
		case 2:
			b = FSearchOt(array, n, 1);
			x++;
			break;
		}
		for (int i = 0; i < n && i >= 0; i++)
		{
			s = 0;
			for (int j = 0; j < n && j >= 0; j++)
				if (a[i] == b[j])
				{
					s++;
				}
			if (!s)
			{
				a[i] = -1;
			}
		}
	} while (x < 3);
	if (flug == 0)
	{
		for (int i = 0; i < n; i++)
			if (a[i] == -1)
				c++;
		if (c == n)
		{
			puts("\n Ничего не найдено.\n");
			return 0;
		}
		for (int i = 0; i < n && a[i] >= 0; i++)
			Output(array, a[i]);
		return 0;
	}
	if (flug == 1)
	{
		return a;
	}
}