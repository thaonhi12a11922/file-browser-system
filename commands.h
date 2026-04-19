#ifndef COMMANDS_H
#define COMMANDS_H

void cmd_ls();
void cmd_cd(char *args[], int count);
void cmd_pwd();
void cmd_cp(char *args[], int count);
void cmd_rm(char *args[], int count);
void cmd_mv(char *args[], int count);

#endif
