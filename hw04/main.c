#include <stdio.h>
#include <stdlib.h>

/* The main program */
int main(int argc, char *argv[])
{
    char a;
    char last_a;
    int a_input = 0;
    int a_output = 0;
    int a_count = 1;
    while (scanf("%c", &a) == 1)
    {
        if (!(a >= 'A' && a <= 'Z') && a != '\n')
        {
            if (a_count == 1)
            {
                printf("%c", last_a);
                a_output += 1;
            }
            else if (a_count == 2)
            {
                printf("%c%c", last_a, last_a);
                a_output += 2;
            }
            else
            {
                printf("%c%d", last_a, a_count);
                if (a_count > 100)
                {
                    a_output += 4;
                }
                else if (a_count > 10)
                {
                    a_output += 3;
                }
                else
                {
                    a_output += 2;
                }
            }
            a_count = 1;

            fprintf(stderr, "Error: Neplatny symbol!\n");
            return 100;
        }
        else
        {
            if (a_input == 0)
            {
                last_a = a;
            }
            else
            {
                if (last_a == a)
                {
                    a_count++;
                    if (a_count == 255)
                    {
                        printf("%c%d", last_a, a_count);
                        a_output += 4;
                        a_count = 1;
                    }
                }
                else
                {
                    if (a_count == 1)
                    {
                        printf("%c", last_a);
                        a_output += 1;
                    }
                    else if (a_count == 2)
                    {
                        printf("%c%c", last_a, last_a);
                        a_output += 2;
                    }
                    else
                    {
                        printf("%c%d", last_a, a_count);
                        if (a_count > 100)
                        {
                            a_output += 4;
                        }
                        else if (a_count > 10)
                        {
                            a_output += 3;
                        }
                        else
                        {
                            a_output += 2;
                        }
                    }
                    a_count = 1;
                }
                last_a = a;
            }
            a_input++;
            //printf("%c\n", a);
        }
        if (a == '\n')
        {
            a_input--;
            printf("\n");
            fprintf(stderr, "Pocet vstupnich symbolu: %d\n", a_input);
            fprintf(stderr, "Pocet zakodovanych symbolu: %d\n", a_output);
            fprintf(stderr, "Kompresni pomer: %.2f\n", (float)a_output / a_input);
        }
    }
    return 0;
}
