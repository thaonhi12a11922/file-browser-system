#include <stdio.h>
#include <string.h>
#include "parser.h"
#include "commands.h"

#define MAX_INPUT 1024
#define MAX_ARGS 10

int main() {
    char input[MAX_INPUT];
    char *args[MAX_ARGS];

    while (1) {
        printf("file-browser> ");

        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        int count = parse_input(input, args, MAX_ARGS);

        if (count == 0) continue;

        if (strcmp(args[0], "exit") == 0) {
            break;
        } else if (strcmp(args[0], "ls") == 0) {
            cmd_ls();
        } else if (strcmp(args[0], "cd") == 0) {
            cmd_cd(args, count);
        } else if (strcmp(args[0], "pwd") == 0) {
            cmd_pwd();
        } else if (strcmp(args[0], "cp") == 0) {
            cmd_cp(args, count);
        } else if (strcmp(args[0], "rm") == 0) {
            cmd_rm(args, count);
        } else if (strcmp(args[0], "mv") == 0) {
            cmd_mv(args, count);
        } else {
            printf("Unknown command: %s\n", args[0]);
        }
    }

    return 0;
}