# File Browser System

A simple command-line file browser system implemented in C.

## Features

Supported commands:

- `ls`  
  List files and directories in the current directory

- `cd <directory>`  
  Change current directory

- `pwd`  
  Print current working directory

- `cp <source> <destination>`  
  Copy a file

- `rm <file>`  
  Remove a file

- `mv <source> <destination>`  
  Move or rename a file

- `exit`  
  Exit the program

---

## Project Structure

```text
main.c
parser.c
parser.h
commands.c
commands.h
Makefile
README.md
```

---

## Compilation

Using Makefile:

```bash
make
```

Or compile manually:

```bash
gcc main.c parser.c commands.c -o filebrowser
```

---

## Running the Program

```bash
./filebrowser
```

---

## Example Usage

```bash
file-browser> pwd

file-browser> ls

file-browser> cp test.txt copy.txt

file-browser> mv copy.txt renamed.txt

file-browser> rm renamed.txt

file-browser> exit
```

---

## Libraries Used

- `stdio.h`
- `string.h`
- `unistd.h`
- `dirent.h`

These are standard low-level C libraries.

---

## Notes

- Implemented entirely in C
- Command-line based interface
- Uses modular design with separate parser and command modules
