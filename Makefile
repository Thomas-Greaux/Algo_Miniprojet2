CC=g++
FLAGS=-std=c++11
SOURCEDIR=source/
PROGS=algo.ex stat.ex

all: $(PROGS)

algo.ex: $(SOURCEDIR)algo.cc
	$(CC) $(FLAGS) $^ -o $@

stat.ex: $(SOURCEDIR)stat.cc
	$(CC) $(FLAGS) $^ -o $@
