#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char content[20];
	int count;
} Word;

typedef struct
{
	Word *array;
	int size;
	int wordCount;
	int wordTotal;
} List;

void initList(List *list, int size)
{
	list->size = size;
	list->array = malloc(size * sizeof(Word));
}

void resizeList(List *list)
{
	list->size *= 2;
	list->array = realloc(list->array, list->size * sizeof(Word));
}

void insertWord(List *list, Word content)
{
	if (list->wordCount == list->size)
	{
		resizeList(list);
	}
	list->array[list->wordCount] = content;
	list->wordCount++;
}

void freeList(List *list)
{
	free(list->array);
}

char lower(char input)
{
	if (input >= 'A' && input <= 'Z')
	{
		return 'a' - 'A' + input;
	}
	return input;
}

int compareAlphabet(const void *a, const void *b)
{
	Word *wordA = (Word *)a;
	Word *wordB = (Word *)b;
	char *strA = wordA->content;
	char *strB = wordB->content;
	for (int i = 0; i < strlen(strA); i++)
	{
		return strcmp(strA, strB);
	}
	return 0;
}

int compareCount(const void *a, const void *b)
{
	Word *wordA = (Word *)a;
	Word *wordB = (Word *)b;
	return wordA->count - wordB->count;
}

int main(int argc, char *argv[])
{
	int caseSensitive = 0;
	int wordLenght = -1;
	int sort = 0;

	for (int i = 0; i < argc; i++)
	{
		if (!strcmp("-c", argv[i]))
		{
			caseSensitive = 1;
		}

		if (!strcmp("-l", argv[i]))
		{
			if ((i + 1) <= argc && strtol(argv[i + 1], NULL, 10) >= 0)
			{
				wordLenght = strtol(argv[i + 1], NULL, 10);
			}
			else
			{
				fprintf(stderr, "Warning: Chybna hodnota parametru -l!\n");
			}
		}

		if (!strcmp("-s", argv[i]))
		{
			if ((i + 1) <= argc && (strtol(argv[i + 1], NULL, 10) == 1 || strtol(argv[i + 1], NULL, 10) == 2))
			{
				sort = strtol(argv[i + 1], NULL, 10);
			}
			else
			{
				fprintf(stderr, "Warning: Chybna hodnota parametru -s!\n");
			}
		}
	}

	//printf("%i\n", caseSensitive);
	//printf("%i\n", strtol("aes\0gjhkhjklgs",NULL,10));
	//printf("%c\n", lower('A'));
	//printf("%i",strcmp("gwag\0qgwdsg","gwag\0agwq"));
	List list;
	list.wordTotal = 0;
	list.wordCount = 0;
	initList(&list, 8);
	char textRaw[20];
	while (scanf("%s ", textRaw) >= 0)
	{
		char textCleaned[20];
		//strcpy(word.content,textRaw);
		int j = 0; // clean text
		for (int i = 0; i < 20; i++)
		{
			if (textRaw[i] == '\0')
			{
				break;
			}
			if ((textRaw[i] >= 'a' && textRaw[i] <= 'z') || (textRaw[i] >= 'A' && textRaw[i] <= 'Z'))
			{
				if (caseSensitive)
				{
					textCleaned[j] = textRaw[i];
				}
				else
				{
					textCleaned[j] = lower(textRaw[i]);
				}
				j++;
			}
		}
		textCleaned[j] = '\0';

		int i = 0;
		while (i < list.wordCount) // check if the word exist
		{
			Word word = list.array[i];
			if (strcmp(word.content, textCleaned) == 0)
			{
				break;
			}
			i++;
		}

		if (i == list.wordCount) // new word
		{
			Word word;
			strcpy(word.content, textCleaned);
			word.count = 1;
			insertWord(&list, word);
			list.wordTotal++;
		}
		else //existing word on index i
		{
			list.array[i].count += 1;
			list.wordTotal++;
		}
	}

	if (sort == 2)
		qsort(list.array, list.wordCount, sizeof(Word), compareAlphabet);
	if (sort == 1)
		qsort(list.array, list.wordCount, sizeof(Word), compareCount);
	if (wordLenght != 0)
		printf("Seznam slov:\n");
	int min = list.array[0].count, max = list.array[0].count;
	for (int i = 0; i < list.wordCount; i++)
	{
		Word word = list.array[i];
		if (min > word.count)
			min = word.count;
		if (max < word.count)
			max = word.count;
		if (wordLenght == -1)
		{
			printf("%-20s %i\n", word.content, word.count);
		}
		else
		{
			if (strlen(word.content) == wordLenght)
			{
				printf("%-20s %i\n", word.content, word.count);
			}
		}
	}

	printf("%-20s %i\n", "Pocet slov:", list.wordCount);

	printf("Nejcastejsi:         ");
	int counter = 0;
	for (int i = 0; i < list.wordCount; i++)
	{
		if (list.array[i].count == max)
		{
			if (counter == 0)
			{
				printf("%s", list.array[i].content);
				counter++;
			}
			else
			{
				printf(" %s", list.array[i].content);
				counter++;
			}
		}
	}
	printf("\nNejmene caste:       ");
	counter = 0;
	for (int i = 0; i < list.wordCount; i++)
	{
		if (list.array[i].count == min)
		{
			if (counter == 0)
			{
				printf("%s", list.array[i].content);
				counter++;
			}
			else
			{
				printf(" %s", list.array[i].content);
				counter++;
			}
		}
	}
	printf("\n");
	freeList(&list);
	return 0;
}
