waiting_list:	readline.o	request.o	waiting_list.o
	gcc	-o	waiting_list	waiting_list.o	request.o	readline.o

waiting_list.o:	waiting_list.c	request.c	request.h	readline.c	readline.h
	gcc	-c	waiting_list.c

request.o:	request.c	request.h	readline.c	readline.h
	gcc	-c	request.c

readline.o:	readline.c	readline.h
	gcc	-c	readline.c
