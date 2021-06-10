program: program.o weatherstats.o
	gcc -std=c11 -Wall -fmax-errors=10 -Wextra program.o weatherstats.o weatherio.o -o program

program.o: program.c weatherstats.h
	gcc -std=c11 -Wall -fmax-errors=10 -Wextra -c program.c -o program.o

weatherio.o: weatherio.c
	gcc -std=c11 -Wall -fmax-errors=10 -Wextra -c weatherio.c -o weatherio.o

weatherstats.o: weatherstats.c
	gcc -std=c11 -Wall -fmax-errors=10 -Wextra -c weatherstats.c -o weatherstats.o

clean:
	rm -f weatherstats.o weatherio.o program.o program
