INC = -Iinc
SRC = $(wildcard src/*.c)
LIBS = -lncurses
GCCWALL = gcc -g -Wall

all:
	$(GCCWALL) $(INC) $(SRC) -o tlights $(LIBS)
