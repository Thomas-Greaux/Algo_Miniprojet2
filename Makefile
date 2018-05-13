CC=g++
FLAGS=-std=c++11
SOURCEDIR=source/
PROGS=algo.ex stat.ex

all: $(PROGS)

algo.ex: algo.o
	$(CC) $(FLAGS) $^ $@

stat.ex: $(SOURCEDIR)stat.cc
	$(CC) $(FLAGS) $^ -o $@

algo.o: $(SOURCEDIR)algo.cc $(SOURCEDIR)arrete.h
	$(CC) $(FLAG) $(SOURCEDIR)algo.cc

arrete.o: $(SOURCEDIR)arrete.cc $(SOURCEDIR)arrete.h
	$(CC) $(FLAG) $(SOURCEDIR)arrete.cc

clean:
	rm -f $(PROGS)
