#include <stdio.h>
#include <stdlib.h>

/* The main program */
int main(int argc, char *argv[])
{
    int a, b;
    scanf("%d %d",&a,&b);
    if (a < -10000 || a > 10000 || b < -10000 || b > 10000)
    {
        printf("Vstup je mimo interval!\n");
        return 0;
    }
    printf("Desitkova soustava: %d %d\n", a, b);
    printf("Sestnactkova soustava: %x %x\n", a, b);
    printf("Soucet: %d + %d = %d\n", a, b, a + b);
    printf("Rozdil: %d - %d = %d\n", a, b, a - b);
    printf("Soucin: %d * %d = %d\n", a, b, a * b);
    if (b != 0)
        printf("Podil: %d / %d = %d\n", a, b, a / b);
    else
        printf("Nedefinovany vysledek!\n");
    printf("Prumer: %.1f\n",(double)(a+b)/2);
    return 0;
}
