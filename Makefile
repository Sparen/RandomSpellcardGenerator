# USAGE:
#
# // to compile:
# make
# // remove compilation output files:
# make clean

# make variables let us avoid pasting these options in multiple places
CC = g++ 
CCFLAGS = -std=c++11 -Wall -Wextra -pedantic -O         # for final build

bin: gen

generator.o: generator.cc
	$(CC) $(CCFLAGS) -c generator.cc

gen: generator.o
	$(CC) $(CCFLAGS) -o generator generator.o

clean: 
	rm -f *.o generator *# *~