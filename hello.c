#include <stdio.h>
#include <string.h>

/*
 * This file has been formatted with
 * clang-format -i hello.c --style=Microsoft
 *
 * To create a format config file:
 * clang-format -style=Microsoft -dump-config > .clang-format
 */

void readLine(char *buffer)
{
    if (NULL == buffer || NULL == fgets(buffer, BUFSIZ, stdin))
        return;

    char *p = strchr(buffer, '\n');

    if (NULL != p)
        *p = '\0';
}

int readNumber(char *prompt)
{
    int number = 0;
    for (;;)
    {
        printf("%s", prompt);
        char line[BUFSIZ] = {'\0'};
        readLine(line);
        if ('\0' == line[0] || 0 == sscanf(line, "%d", &number))
        {
            printf("Your input is wrong\n");
        }
        else
        {
            return number;
        }
    }
}

#define OPTION_1 1
#define OPTION_2 2
#define OPTION_3 3

#define OPTION_A 'A'
#define OPTION_B 'B'
#define OPTION_C 'C'

void show(int r, int c, int m[][c])
{
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            printf("* %2d *", m[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    int number = 0;
    while (-1 != number)
    {
        number = readNumber("Insert number (enter -1 to end): ");
        printf("Your number is %d\n", number);
    }

    while (1)
    {
        printf("Insert a line (enter quit to end):\n");
        char line[BUFSIZ] = {'\0'};
        readLine(line);
        if (0 == strcmp("quit", line))
        {
            break;
        }
        printf("Your line is:\n");
        printf("%s\n", line);
    }

    // -- Menu skeleton - Numeric input
    int exit = 0;
    while (!exit)
    {
        switch (readNumber("Insert an option or -1 to exit: "))
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
        readLine(choice);
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

    // -- Passing a dynamic size multidimensional array to a function

    int r = 2;
    int c = 3;
    int m[r][c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++) {
            m[i][j] = i + j;
        }
    }

    show(r, c, m);

    return 0;
}
