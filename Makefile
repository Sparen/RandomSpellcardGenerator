# USAGE:
#
# // to compile:
# make
# // remove compilation output files:
# make clean

# make variables let us avoid pasting these options in multiple places
CC = g++ 
CCFLAGS = -std=c++11 -Wall -Wextra -pedantic -O # for final build

bin: gen

generator_fxn.o: generator_fxn.cc generator_fxn.h
	$(CC) $(CCFLAGS) -c generator_fxn.cc

generator.o: generator.cc generator_fxn.h
	$(CC) $(CCFLAGS) -c generator.cc

gen: generator.o generator_fxn.o
	$(CC) $(CCFLAGS) -o generator generator.o generator_fxn.o

clean: 
	rm -f *.o generator *# *~
