#include <stdio.h>
#include <string.h>

/*
 * This file has been formatted with
 * clang-format -i hello.c --style=Microsoft
 *
 * To create a format config file:
 * clang-format -style=Microsoft -dump-config > .clang-format
 */

void leggiRiga(char *buffer)
{
    if (NULL == buffer || NULL == fgets(buffer, BUFSIZ, stdin))
        return;

    char *p = strchr(buffer, '\n');

    if (NULL != p)
        *p = '\0';
}

int leggiNumero(char *prompt)
{
    int numero = 0;
    for (;;)
    {
        printf("%s", prompt);
        char riga[BUFSIZ] = {'\0'};
        leggiRiga(riga);
        if ('\0' == riga[0] || 0 == sscanf(riga, "%d", &numero))
        {
            printf("Immissione errata\n");
        }
        else
        {
            return numero;
        }
    }
}

#define OPTION_1 1
#define OPTION_2 2
#define OPTION_3 3

#define OPTION_A 'A'
#define OPTION_B 'B'
#define OPTION_C 'C'

int main(int argc, char const *argv[])
{
    int number = 0;
    while (-1 != number)
    {
        number = leggiNumero("Inserici numero (immetti -1 per terminare): ");
        printf("Hai inserito %d\n", number);
    }

    while (1)
    {
        printf("Inserisci una riga (immetti quit per finire):\n");
        char riga[BUFSIZ] = {'\0'};
        leggiRiga(riga);
        if (0 == strcmp("quit", riga))
        {
            break;
        }
        printf("La tua riga è:\n");
        printf("%s\n", riga);
    }

    // -- Menu skeleton - Numeric input
    int exit = 0;
    while (!exit)
    {
        switch (leggiNumero("Insert an option or -1 to exit: "))
        {
        case OPTION_1:
            printf("Handling option 1\n");
            break;
        case OPTION_2:
            printf("Handling option 2\n");
            break;
        case OPTION_3:
            printf("Handling option 3\n");
            break;
        case -1:
            printf("Quitting\n");
            exit = 1;
            break;
        default:
            printf("Wrong choice\n");
            break;
        }
    }
    // --

    // -- Menu skeleton - Char input
    exit = 0;
    while (!exit)
    {
        printf("Enter an option or q to quit: ");
        char choice[BUFSIZ] = {'\0'};
        leggiRiga(choice);
        switch (choice[0])
        {
        case OPTION_A:
            printf("Handling option A\n");
            break;
        case OPTION_B:
            printf("Handling option B\n");
            break;
        case OPTION_C:
            printf("Handling option C\n");
            break;
        case 'q':
            printf("Quitting\n");
            exit = 1;
            break;
        default:
            printf("Wrong choice\n");
            break;
        }
    }
    // --

    return 0;
}
