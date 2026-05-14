#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include "commands.h"

void cmd_cp(char *args[], int count) {
    if (count != 3) {
        printf("Usage: cp <source> <destination>\n");
        return;
    }

    FILE *src = fopen(args[1], "rb");
    if (src == NULL) {
        perror("cp");
        return;
    }

    FILE *dest = fopen(args[2], "wb");
    if (dest == NULL) {
        perror("cp");
        fclose(src);
        return;
    }

    char buffer[1024];
    size_t bytes;

    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(src);
    fclose(dest);
}

void cmd_rm(char *args[], int count) {
    if (count != 2) {
        printf("Usage: rm <filename>\n");
        return;
    }

    if (remove(args[1]) == 0) {
        printf("File removed successfully\n");
    } else {
        perror("rm");
    }
}

void cmd_mv(char *args[], int count) {
    if (count != 3) {
        printf("Usage: mv <source> <destination>\n");
        return;
    }

    if (rename(args[1], args[2]) == 0) {
        printf("File moved/renamed successfully\n");
    } else {
        perror("mv");
    }
}

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