//
// Created by daruuu on 12/2/24.
//
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 1000


int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

int main()
{
	int	array_left[MAX_LINES];
	int	array_right[MAX_LINES];
	int count;

	count = 0;
	FILE *file = fopen("/home/daruuu/CLionProjects/adventOfCode_2024/aoc_day01/input.txt", "r");
	if (file == NULL)
	{
		perror("Error opening file\n");
		return (1);
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

	return (0);
}
