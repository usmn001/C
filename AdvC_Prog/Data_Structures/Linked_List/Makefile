#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************


#define the C Compiler to use 
CC	= gcc
#define compiler flags
CFLAGS	= -std=c11 -Wall -fmax-errors=10 -Wextra
#define library paths in addition to /usr/lib
LFLAGS	= 
#define libraries to use
LIBS	=
#define the object files that this project needs
OBJFILES	= Linked_List.o
#define the name of executable file
MAIN	= program

# all of the below is generic - are typically only adjusts the above

all: $(MAIN)

$(MAIN): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJFILES)
	
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<
	
clean:
	rm -f $(OBJFILES) $(MAIN)


