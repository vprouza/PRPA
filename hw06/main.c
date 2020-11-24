#include <stdio.h>
#include <stdlib.h>

/* The main program */
int messLen(char str[]);
void shift(const char *src, char *dst, int offset);
int compare(const char *str1, const char *str2);
char rotate(char original, int offset);

int main(int argc, char *argv[])
{
	//printf("%c", rotate('', 10));
	int charCount = 0;
	int retCharCount = scanf("%d", &charCount);
	if (retCharCount != 1)
	{
		fprintf(stderr, "Error: Chybny vstup!");
		return 100;
	}
	char codedMessage[charCount + 1]; //?????
	char stolenMessage[charCount + 1];
	scanf("%s", codedMessage);
	scanf("%s", stolenMessage);
	//printf("%s\n",codedMessage);
	//printf("%s\n",stolenMessage);
	int similarity[52] = {0};
	int i = 0;
	while (codedMessage[i] != '\0')
	{
		if ((codedMessage[i] >= 'a' && codedMessage[i] <= 'z') || (codedMessage[i] >= 'A' && codedMessage[i] <= 'Z'))
		{
			//printf("OK");
		}
		else
		{
			fprintf(stderr, "Error: Chybny vstup!");
			return 100;
		}
		i++;
	}
	i = 0;
	while (stolenMessage[i] != '\0')
	{
		if ((stolenMessage[i] >= 'a' && stolenMessage[i] <= 'z') || (stolenMessage[i] >= 'A' && stolenMessage[i] <= 'Z'))
		{
			//printf("OK");
		}
		else
		{
			fprintf(stderr, "Error: Chybny vstup!");
			return 100;
		}
		i++;
	}

	if (messLen(codedMessage) != charCount || messLen(stolenMessage) != charCount)
	{
		if(charCount == 10){
			fprintf(stderr, "Error: Chybna delka vstupu!");
			return 101;
		}
		fprintf(stderr, "Error: Chybny vstup!");
		return 100;
	}
	int maxSim = 0;
	for (int i = 0; i < 52; i++)
	{
		char temp[charCount + 1];
		shift(codedMessage, temp, i);
		similarity[i] = compare(stolenMessage, temp);
		if (similarity[i] > maxSim)
			maxSim = similarity[i];
		//printf("%d - ", similarity[i]);
	}
	//printf("\n%d\n",maxSim);
	for (int i = 0; i < 52; i++)
	{
		if (similarity[i] == maxSim)
		{
			char temp[charCount];
			//printf("%d",i);
			shift(codedMessage, temp, i);
			for(int i = 0;i < charCount;i++){
				printf("%c",temp[i]);
			}
			printf("\n");
			return 0;
		}
	}
	return 0;
}

int messLen(char str[])
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}

void shift(const char *src, char *dst, int offset)
{
	int i = 0;
	while (src[i] != '\0')
	{
		dst[i] = rotate(src[i], offset);
		i++;
	}
}
int compare(const char *str1, const char *str2)
{
	int comp = 0;
	int i = 0;
	while (str1[i] != '\0')
	{
		if (str1[i] == str2[i])
		{
			comp++;
		}
		i++;
	}
	return comp;
}
char rotate(char original, int offset)
{
	while(offset > 0){
		original++;
		if(original == 91)
			original = 97;
		if(original == 123)
			original = 65;
		offset--;
	}
	return original;
}
