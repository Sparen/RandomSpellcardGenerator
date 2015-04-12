# USAGE:
#
# // to compile:
# make
# // remove compilation output files:
# make clean

# make variables let us avoid pasting these options in multiple places
CC = g++ 
CCFLAGS = -std=c++11 -Wall -Wextra -pedantic -O
#CCFLAGS = -std=c++11 -Wall -Wextra -pedantic -g -O

bin: gen

wordsep.o: wordsep.cc wordsep.h
	$(CC) $(CCFLAGS) -c wordsep.cc

generator_fxn.o: generator_fxn.cc generator_fxn.h
	$(CC) $(CCFLAGS) -c generator_fxn.cc

generator.o: generator.cc generator_fxn.h wordsep.h
	$(CC) $(CCFLAGS) -c generator.cc

gen: generator.o generator_fxn.o wordsep.o
	$(CC) $(CCFLAGS) -o generator generator.o generator_fxn.o wordsep.o

clean: 
	rm -f *.o generator *# *~ *.exe *.gcov *.gcda *.gcno
