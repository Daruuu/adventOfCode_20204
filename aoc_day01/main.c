//
// Created by daruuu on 12/2/24.
//
#include <stdio.h>
#include <stdlib.h>
int	count_occurrences(const int *array, int count, int value);

#define MAX_LINES 1000


int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

void	day_01_part01(void)
{
	int	array_left[MAX_LINES];
	int	array_right[MAX_LINES];
	int count;

	count = 0;
	FILE *file = fopen("/home/daruuu/CLionProjects/adventOfCode_2024/aoc_day01/input_01.txt", "r");
	if (file == NULL)
	{
		perror("Error opening file\n");
//		return (1);
	}
	while (fscanf(file, "%d %d", &array_left[count], &array_right[count]) != EOF)
	{
		count++;
		if (count > 1000)
		{
			printf("se a excedido el maximo de elementos\n");
			break;
		}
	}
	fclose(file);
	int i = 0;

	qsort(array_left, count, sizeof(int), compare);
	qsort(array_right, count, sizeof(int), compare);

	int distancia_entre_numeros = 0;
	int total_distancia = 0;
	while (i < MAX_LINES)
	{
		distancia_entre_numeros = abs(array_left[i] - array_right[i]);
		total_distancia += distancia_entre_numeros;
		i ++;
	}
	printf("%d\n", total_distancia);
}

int	calcular_simularity_score(int *array_left, int *array_right, int count)
{
	int i;
	int simulitud_score = 0;

	i = 0;
	while (i < count)
	{
		int ocurrences = count_occurrences(array_right, count, array_left[i]);
		simulitud_score = simulitud_score + (array_left[i] * ocurrences);
		i++;
	}
	return (simulitud_score);
}

int	count_occurrences(const int *array, int count, int value)
{
	int	occurrences = 0;
	int i;

	i = 0;
	while (i < count)
	{
		if (array[i] == value)
			occurrences ++;
		i ++;
	}
	return (occurrences);
}

void	day_01_part02(void)
{
	int	array_left[MAX_LINES];
	int	array_right[MAX_LINES];
	int count;

	count = 0;
	FILE *file = fopen("/home/daruuu/CLionProjects/adventOfCode_2024/aoc_day01/input_02.txt", "r");
	if (file == NULL)
	{
		perror("Error opening file\n");
		return ;
	}
	while (fscanf(file, "%d %d", &array_left[count], &array_right[count]) != EOF)
	{
		count++;
		if (count > 1000)
		{
			printf("se a excedido el maximo de elementos\n");
			break;
		}
	}
	fclose(file);

	int similarity_score;
	similarity_score = calcular_simularity_score(array_left, array_right, count);
	printf("resutl part 2: %d\n", similarity_score);

}

int main(void)
{
	day_01_part01();
	day_01_part02();

	return (0);
}
