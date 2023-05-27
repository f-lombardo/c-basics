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
        switch (leggiNumero("Inserisci un'opzione o -1 per terminare: "))
        {
        case OPTION_1:
            printf("Gestione dell'opzione 1\n");
            break;
        case OPTION_2:
            printf("Gestione dell'opzione 2\n");
            break;
        case OPTION_3:
            printf("Gestione dell'opzione 3\n");
            break;
        case -1:
            printf("Fine\n");
            exit = 1;
            break;
        default:
            printf("Scelta errata\n");
            break;
        }
    }
    // --

    // -- Menu skeleton - Char input
    exit = 0;
    while (!exit)
    {
        printf("Inserisci un'opzione oppure q per uscire: ");
        char scelta[BUFSIZ] = {'\0'};
        leggiRiga(scelta);
        switch (scelta[0])
        {
        case OPTION_A:
            printf("Gestione dell'opzione A\n");
            break;
        case OPTION_B:
            printf("Gestione dell'opzione B\n");
            break;
        case OPTION_C:
            printf("Gestione dell'opzione C\n");
            break;
        case 'q':
            printf("Uscita\n");
            exit = 1;
            break;
        default:
            printf("Scelta errata\n");
            break;
        }
    }
    // --

    return 0;
}
