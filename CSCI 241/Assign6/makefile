#
# PROGRAM:    Assign6
# PROGRAMMER: Mason Greig
# LOGON ID:   z1768935
# DATE DUE:   11/02/2016
#

# Compiler variables
CCFLAGS = -ansi -Wall -std=c++11

# Rule to link object code files to create executable file
Assign6: Assign6.o Queue.o
	g++ $(CCFLAGS) -o Assign6 Assign6.o Queue.o

# Rules to compile source code files to object code
Assign6.o: Assign6.cpp Queue.h
	g++ $(CCFLAGS) -c Assign6.cpp

Queue.o: Queue.cpp Queue.h
	g++ $(CCFLAGS) -c Queue.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o Assign6


