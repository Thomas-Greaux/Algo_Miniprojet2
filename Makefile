CC=g++
FLAGS=-std=c++11
SOURCEDIR=source/
SRC=$(wildcard $(SOURCEDIR)*.cc)
SRC := $(filter-out $(SOURCEDIR)algo.cc $(SOURCEDIR)stat.cc, $(SRC))
OBJ=$(SRC:.cc=.o)
PROGS=algo.ex stat.ex

all: $(PROGS)

algo.ex: $(SOURCEDIR)algo.o $(OBJ)
	$(CC) $(FLAGS) $^ -o $@

stat.ex: $(SOURCEDIR)stat.o $(OBJ)
	$(CC) $(FLAGS) $^ -o $@
    
%.o : %.cc
	$(CC) -c $(FLAGS) -o $@ $^

clean:
	rm -f $(PROGS)
	rm -f $(OBJ)
	rm -f $(SOURCEDIR)algo.o
	rm -f $(SOURCEDIR)stat.o
