#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int *array;
	int size;
	int numCount;
} List;

void initList(List *list, int size)
{
	list->size = size;
	list->array = malloc(size * sizeof(int));
}

void resizeList(List *list)
{
	list->size *= 2;
	list->array = realloc(list->array, list->size * sizeof(int));
}

void insertNumber(List *list, int number)
{
	if (list->numCount == list->size)
	{
		resizeList(list);
	}
	list->array[list->numCount] = number;
	list->numCount++;
}

void freeList(List *list)
{
	free(list->array);
}

int compare(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int main(int argc, char *argv[])
{
	// TODO - insert your code here
	List list;
	initList(&list, 8);

	int stat = 0;
	int bins;
	stat = scanf("%d ", &bins);

	if (stat < 1)
	{
		fprintf(stderr, "Error: Chyba histogramu!\n");
		return 100;
	}
	int numCount = 0;
	int num;
	int cont = 1;
	do
	{
		stat = scanf("%d ", &num);
		if (stat == 1)
		{
			//printf("%d",num);

			insertNumber(&list, num);
			numCount++;
		}
		else
		{
			cont = 0;
		}

	} while (cont);
	int *data;
	data = malloc(numCount * sizeof(int));
	memcpy(data, list.array, numCount * sizeof(int));
	//printf("\nend - %d\n", numCount);
	qsort(data, numCount, sizeof(int), compare);
	double median;
	if(numCount % 2 == 1){
		median = data[numCount/2];
	}else{
		median = (data[numCount/2] + data[(numCount/2)-1]) / 2;
	}
	/*for (int i = 0; i < numCount; i++)
	{
		printf("%d ", data[i]);
	}
	printf("\n");*/
	
	printf("Median %.2f\n", median);
	printf("Pocet cisel: %d\n", numCount);
	printf("Min. hodnota: %d\n", data[0]);
	printf("Max. hodnota: %d\n", data[numCount-1]);
	return 0;
}
