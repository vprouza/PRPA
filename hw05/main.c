#include <stdio.h>
#include <stdlib.h>

/* The main program */

int error(int a)
{
	switch (a)
	{
	case 100:
		fprintf(stderr, "Error: Chybny vstup!\n");
		return 100;
		break;

	case 101:
		fprintf(stderr, "Error: Vstup mimo interval!\n");
		return 101;
		break;

	case 102:
		fprintf(stderr, "Error: Sirka neni liche cislo!\n");
		return 102;
		break;

	case 103:
		fprintf(stderr, "Error: Neplatna velikost plotu!\n");
		return 103;
		break;
	}
	return 0;
}

void printNspaces(int n)
{
	for (int i = n; i > 0; i--)
	{
		printf(" ");
	}
}

void fillN(int n, int s)
{
	for (int i = n; i > 0; i--)
	{
		if (!s)
		{
			if (i % 2 == 1)
				printf("o");
			else
				printf("*");
		}
		else
		{
			if (i % 2 == 0)
				printf("o");
			else
				printf("*");
		}
	}
}

void fenceN(int n, int s)
{
	for (int i = n; i > 0; i--)
	{
		if (n % 2)
		{
			if (i % 2 == 1)
				printf("|");
			else
			{
				if (s)
					printf("-");
				else
					printf(" ");
			}
		}
		else
		{
			if (i % 2 == 0)
			{
				if (s)
					printf("-");
				else
					printf(" ");
			}
			else
				printf("|");
		}
	}
}

void filledSquare(int a, int c)
{
	for (int i = a; i > 0; i--)
	{
		if (i == a || i == 1)
		{
			for (int j = a; j > 0; j--)
			{
				printf("X");
			}
		}
		else
		{
			printf("X");
			fillN(a - 2, i % 2);
			printf("X");
		}
		if (i <= c)
		{
			if (i == c || i == 1)
				fenceN(c, 1);
			else
				fenceN(c, 0);
		}
		printf("\n");
	}
}

void rectangle(int a, int b, int c)
{
	for (int i = b; i > 0; i--)
	{
		if (i == b || i == 1)
		{
			for (int j = a; j > 0; j--)
			{
				printf("X");
			}
		}
		else
		{
			printf("X");
			printNspaces(a - 2);
			printf("X");
		}
		if (i <= c)
		{
			if (i == c || i == 1)
				fenceN(c, 1);
			else
				fenceN(c, 0);
		}
		printf("\n");
	}
}

void house(int a, int b, int c)
{
	for (int i = 0; i < a / 2; i++)
	{
		printNspaces(a / 2 - i);
		if (i == 0)
		{
			printf("X\n");
		}
		else
		{
			printf("X");
			printNspaces(i * 2 - 1);
			printf("X\n");
		}
	}
	if (a == b)
	{
		filledSquare(a, c);
	}
	else
	{
		rectangle(a, b, c);
	}
}

int main(int argc, char *argv[])
{
	int a, b, c;
	int retA = scanf("%d", &a);
	int retB = scanf("%d", &b);
	int retC = scanf("%d", &c);
	//printf("%d\n", ret);
	//printf("%d,%d,%d\n", retA, retB, retC);
	//printf("%d,%d,%d\n", a, b, c);
	if (retA == 0 || retB == 0 || retC == 0)
	{
		return error(100);
	}
	if (retA == 1 && retB == -1)
	{
		if (!(a >= 3 && a <= 69))
		{
			return error(101);
		}
		rectangle(a, a, 0);
	}
	if (retA == 1 && retB == 1 && retC == -1)
	{
		if (!(a >= 3 && a <= 69 && b >= 3 && b <= 69))
		{
			return error(101);
		}
		//printf("%d",b%2);
		if (a % 2 == 0)
		{
			return error(102);
		}
		house(a, b, 0);
	}
	if (retA == 1 && retB == 1 && retC == 1)
	{
		if (!(a >= 3 && a <= 69 && b >= 3 && b <= 69 && c >= 3 && c <= 69))
		{
			return error(101);
		}
		if (a % 2 == 0)
		{
			return error(102);
		}
		if (c >= b)
		{
			return error(103);
		}
		house(a, b, c);
	}
	return 0;
}
