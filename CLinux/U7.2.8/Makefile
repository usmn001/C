# define the C compiler to use
CC       = gcc

#define library compilation command to use
LC       = ar 

#define library compilation flags
LCFLAGS   = rcs

# define comipler flags
CFLAGS   = -std=c11 -Wall -fmax-errors=10 -Wextra

# define library paths inherst addition to /usr/lib
LFLAGS   = -L. 

# define libraries to use
LIBS = -lweather

# define library name to compile and use
LIBN = libweather.a

# define the object files that this project needs
OBJ0 = program.o  
OBJ1 = weatherstats.o
OBJ2 = weatherio.o

#define name of src files to use 
SRC0 = program.c
SRC1 = weatherstats.c
SRC2 = weatherio.c

# define the name of the executable file
MAIN     = program

# all of the below is generic - one typically only adjusts the above

$(MAIN): $(OBJ0) $(LIBN)
	$(CC) $(CFLAGS) $(OBJ0) $(LFLAGS) $(LIBS) -o $(MAIN)
	
$(LIBN): $(OBJ1) $(OBJ2)
	$(LC) $(LCFLAGS) $(LIBN) $(OBJ1) $(OBJ2)  

$(OBJ0): $(SRC0)
	$(CC) $(CFLAGS) -c $(SRC0) -o $(OBJ0)

$(OBJ1): $(SRC1)
	$(CC) $(CFLAGS) -c $(SRC1) -o $(OBJ1) 

$(OBJ2): $(SRC2)
	$(CC) $(CFLAGS) -c $(SRC2) -o $(OBJ2)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

launch: program
	./program

clean:
	rm -f *.o $(MAIN) $(P1)

