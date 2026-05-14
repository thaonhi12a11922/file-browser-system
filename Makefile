filebrowser: main.c parser.c commands.c
	gcc main.c parser.c commands.c -o filebrowser

clean:
	rm -f filebrowser