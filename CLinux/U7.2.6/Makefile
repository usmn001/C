program: program.o libweather.a 
	gcc -std=c11 -Wall -fmax-errors=10 -Wextra program.o -L. -lweather -o program

program.o: program.c 
	gcc -std=c11 -Wall -fmax-errors=10 -Wextra -c program.c -o program.o

libweather.a: weatherstats.o weatherio.o
	ar rcs libweather.a weatherstats.o weatherio.o

weatherstats.o: weatherstats.c
	gcc -std=c11 -Wall -fmax-errors=10 -Wextra -o weatherstats.o -c weatherstats.c

weatherio.o: weatherio.c
	gcc -std=c11 -Wall -fmax-errors=10 -Wextra -c weatherio.c -o weatherio.o

launch : program
	./program
clean:
	rm -f *.o libweather.a program
