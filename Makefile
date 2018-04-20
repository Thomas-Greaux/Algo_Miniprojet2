CC= g++
PATH=source/
PROGS= algo.ex stat.ex

all: $(PROGS)

algo.ex: $(PATH)algo.cc
	$(CC) $^ -o $@

stat.ex: $(PATH)stat.cc
	$(CC) $^ -o $@
