#include <stdio.h>
#include <stdlib.h>

/* The main program */
int main(int argc, char *argv[])
{
    char readingStatus = -1;
    int number = 0;
    int counter = 0;
    int positiveCounter = 0, negativeCounter = 0;
    int evenCounter = 0, oddCounter = 0;
    long sum = 0;
    int min = 0, max = 0;

    do
    {
        readingStatus = scanf("%d", &number);

        if (readingStatus > 0)
        {
            if (number <= 10000 && number >= -10000)
            {

                if (counter != 0)
                {
                    printf(", %d", number);
                    if (number > max)
                        max = number;
                    if (number < min)
                        min = number;
                }
                else
                {
                    printf("%d", number);
                    min = 0;
                    max = 0;
                }
                counter++;
                sum += number;

                if (number > 0)
                    positiveCounter++;
                else if (number < 0)
                    negativeCounter++;

                if (number % 2)
                    oddCounter++;
                else
                    evenCounter++;
            }
            else
            {
                printf("\nError: Vstup je mimo interval!\n");
                return 100;
            }
        }
        else
        {
            printf("\n");
            printf("Pocet cisel: %d\n", counter);
            printf("Pocet kladnych: %d\n", positiveCounter);
            printf("Pocet zapornych: %d\n", negativeCounter);
            printf("Procento kladnych: %.2f\n", (double)positiveCounter / counter * 100);
            printf("Procento zapornych: %.2f\n", (double)negativeCounter / counter * 100);
            printf("Pocet sudych: %d\n", evenCounter);
            printf("Pocet lichych: %d\n", oddCounter);
            printf("Procento sudych: %.2f\n", (double)evenCounter / counter * 100);
            printf("Procento lichych: %.2f\n", (double)oddCounter / counter * 100);
            printf("Prumer: %.2f\n", (double)sum / counter);
            printf("Maximum: %d\n", max);
            printf("Minimum: %d\n", min);
        }

    } while (readingStatus > 0);
    return 0;
}
