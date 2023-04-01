#include <stdio.h>
#include <string.h>

void readLine(char *buffer)
{
    if (NULL == buffer || NULL == fgets(buffer, BUFSIZ, stdin))
        return;

    char *p = strchr(buffer, '\n');

    if (NULL != p)
        *p = '\0';
}

int readNumber(char *prompt) {
    int number = 0;
    for(;;) {
        printf("%s", prompt);
        char line[BUFSIZ] = { '\0' };
        readLine(line);
        if ('\0' == line[0] || 0 == sscanf(line, "%d", &number)) {
            printf("Your input is wrong\n");
        } else {
            return number;
        }
    }
}

int main(int argc, char const *argv[]) {
    int number = 0;
    while (-1 != number) {
        number = readNumber("Insert number (enter -1 to end): ");
        printf("Your number is %d\n", number);
    }

    while(1) {
        printf("Insert a line (enter quit to end):\n");
        char line[BUFSIZ] = { '\0'};
        readLine(line);
        if (0 == strcmp("quit", line)) {
            break ;
        }
        printf("Your line is:\n");
        printf("%s\n", line);
    }

    return 0;
}
