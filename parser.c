#include <string.h>
#include "parser.h"

int parse_input(char *input, char *args[], int max_args) {
    int count = 0;

    // remove newline
    input[strcspn(input, "\n")] = '\0';

    char *token = strtok(input, " ");

    while (token != NULL && count < max_args) {
        args[count++] = token;
        token = strtok(NULL, " ");
    }

    return count;
}