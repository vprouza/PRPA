#include <stdio.h>
#include <stdlib.h>

/* The main program */

int readMatrice(int *matrice, int rows, int columns);
void printMatrice(int *matrice, int rows, int columns);
void sumMatrice(int *matriceA, int *matriceB, int *matriceOut, int size);
void diffMatrice(int *matriceA, int *matriceB, int *matriceOut, int size);
void prodMatrice(int *matriceA, int *matriceB, int *matriceOut, int rowsA, int columnsA, int rowsB, int columnsB);

int main(int argc, char *argv[])
{
	int rowsA = 0, columnsA = 0;
	int rowsB = 0, columnsB = 0;
	char operation = 0;
	//scanf("%d",&rows);
	//scanf("%d",&columns);
	if (!(scanf("%d", &rowsA) && scanf("%d", &columnsA)))
	{
		fprintf(stderr, "Error: Chybny vstup!\n");
		return 100;
	}
	int matriceA[rowsA * columnsA];
	if (readMatrice(matriceA, rowsA, columnsA) == -1)
	{
		fprintf(stderr, "Error: Chybny vstup!\n");
		return 100;
	}

	//scanf(" %c",&operation);
	if (!scanf(" %c", &operation) || !(operation == '+' || operation == '-' || operation == '*'))
	{
		fprintf(stderr, "Error: Chybny vstup!\n");
		return 100;
	}

	if (!(scanf("%d", &rowsB) && scanf("%d", &columnsB)))
	{
		fprintf(stderr, "Error: Chybny vstup!\n");
		return 100;
	}
	int matriceB[rowsB * columnsB];
	if (readMatrice(matriceB, rowsB, columnsB) == -1)
	{
		fprintf(stderr, "Error: Chybny vstup!\n");
		return 100;
	}

	int matriceOut[rowsA*columnsB];

	switch (operation)
	{
	case '+':
		sumMatrice(matriceA,matriceB,matriceOut, rowsA*columnsA);
		break;
	case '-':
		diffMatrice(matriceA,matriceB,matriceOut, rowsA*columnsA);
		break;
	case '*':
		if (rowsB != columnsA){
			fprintf(stderr, "Error: Chybny vstup!\n");
			return 100;
		}
		prodMatrice(matriceA,matriceB,matriceOut, rowsA, columnsA, rowsB, columnsB);
		break;
	
	default:
		break;
	}
	//printMatrice(matriceA, rowsA, columnsA);
	//printf("%c\n", operation);
	//printMatrice(matriceB, rowsB, columnsB);
	printf("%d %d\n",rowsA, columnsB);
	printMatrice(matriceOut, rowsA, columnsB);
	
	return 0;
}

int readMatrice(int *matrice, int rows, int columns)
{
	for (int i = 0; i < rows * columns; i++)
	{
		int a = 0;
		if (scanf("%d", &a))
		{
			matrice[i] = a;
		}
		else
		{
			return -1;
		}
	}
	return 0;
}

void printMatrice(int *matrice, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (j + 1 == columns)
			{
				printf("%d\n", matrice[(columns * i) + j]);
			}
			else
			{
				printf("%d ", matrice[(columns * i) + j]);
			}
		}
		//printf("\n");
	}
}

void sumMatrice(int *matriceA, int *matriceB, int *matriceOut, int size)
{
	for(int i = 0;i<size;i++){
		matriceOut[i] = matriceA[i] + matriceB[i];
	}
}

void diffMatrice(int *matriceA, int *matriceB, int *matriceOut, int size)
{
	for(int i = 0;i<size;i++){
		matriceOut[i] = matriceA[i] - matriceB[i];
	}
}


void prodMatrice(int *matriceA, int *matriceB, int *matriceOut, int rowsA, int columnsA, int rowsB, int columnsB){
	int rowsOut = rowsA;
	int columnsOut = columnsB;
	
	for (int i = 0; i < rowsOut; i++) // i radek vysledne matice = radek maticeA
	{
		for (int j = 0; j < columnsOut; j++) // j  sloupec vysledne matice = sloupec maticeB
		{
			int sum = 0;
			for (int k = 0; k < columnsA; k++) // k pozice v souctu
			{//                 i=radek  k=sloupec       k=radek j=sloupec
				sum += matriceA[columnsA*i+k] * matriceB[columnsB*k+j];
			}
			
			matriceOut[(columnsOut * i) + j] = sum;
		}
		
	}
	
}


