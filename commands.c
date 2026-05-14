#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include "commands.h"

void cmd_ls() {
    DIR *dir;
    struct dirent *entry;
    // opens the current directory
    dir = opendir(".");
    // checks if the directory was opened successfully
    if (dir == NULL) {
        perror("ls error");
        return;
    }
    // reads and prints each entry in the directory
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    // closes the directory
    closedir(dir);
}

void cmd_cd(char *args[], int count) {
    // checks if the user provided a directory argument
    if (count < 2) {
        printf("Usage: cd <directory>\n");
        return;
    }
    // changes the current working directory to the specified directory
    if (chdir(args[1]) != 0) {
        perror("cd error");
    }
}

void cmd_pwd() {
    // create character array to store the current working directory path
    char cwd[1024];
    // gets the current working directory and prints it
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("%s\n", cwd);
    } else {
        // if there was an getcwd fails, print the error message
        perror("pwd error");
    }
}