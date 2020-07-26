shell: \
			main.o \
			echo.o \
			pwd.o \
			ls.o \
			cd.o \
			pinfo.o \
			exithandler.o \
			fg.o \
			bg.o \
			fork.o \
			redirection.o \
			inputredirection.o \
			outputredirection.o \
			ioredirection.o \
			appendredirection.o \
			piphandler.o \
			splitpipe.o \
			jobs.o \
			kjob.o \
			quit.o \
			setenv.o \
			unsetenv.o \
			overkill.o \
			bbgrbg.o \
			fgbg.o \
			cronjob.o
	$(CC) -g -o shell $^

clean:
	@rm -f *.o shell

main.o: shell.h main.c
	$(CC) -g -c main.c

echo.o: shell.h echo.c
	$(CC) -g -c echo.c

pwd.o : shell.h pwd.c
	$(CC) -g -c pwd.c

ls.o : shell.h ls.c
	$(CC) -g -c ls.c

cd.o : shell.h cd.c
	$(CC) -g -c cd.c

pinfo.o : shell.h pinfo.c
	$(CC) -g -c pinfo.c

exithandler.o : shell.h exithandler.c
	$(CC) -g -c exithandler.c

fg.o : shell.h fg.c
	$(CC) -g -c fg.c

bg.o : shell.h bg.c
	$(CC) -g -c bg.c

fgbg.o : shell.h fgbg.c
	$(CC) -g -c fgbg.c

bbgrbg.o : shell.h bbgrbg.c
	$(CC) -g -c bbgrbg.c

fork.o : shell.h fork.c
	$(CC) -g -c fork.c

redirection.o : shell.h redirection.c
	$(CC) -g -c redirection.c

inputredirection.o : shell.h inputredirection.c
	$(CC) -g -c inputredirection.c

outputredirection.o : shell.h outputredirection.c
	$(CC) -g -c outputredirection.c

ioredirection.o : shell.h ioredirection.c
	$(CC) -g -c ioredirection.c

appendredirection.o : shell.h appendredirection.c
	$(CC) -g -c appendredirection.c

piphandler.o : shell.h piphandler.c
	$(CC) -g -c piphandler.c	

splitpipe.o : shell.h splitpipe.c
	$(CC) -g -c splitpipe.c

jobs.o : shell.h jobs.c
	$(CC) -g -c jobs.c

kjob.o : shell.h kjob.c
	$(CC) -g -c kjob.c

cronjob.o : shell.h cronjob.c
	$(CC) -g -c cronjob.c	

quit.o : shell.h quit.c
	$(CC) -g -c quit.c

setenv.o : shell.h setenv.c
	$(CC) -g -c setenv.c

unsetenv.o : shell.h unsetenv.c
	$(CC) -g -c unsetenv.c
	
overkill.o : shell.h overkill.c
	$(CC) -g -c overkill.c	

