#
# PROGRAM:    Assign7
# PROGRAMMER: Mason Greig
# LOGON ID:   z1768935
# DATE DUE:   11/10/2016
#

# Compiler variables
CCFLAGS = -ansi -Wall -std=c++11

# Rule to link object code files to create executable file
Assign7: Assign7.o
	g++ $(CCFLAGS) -o Assign7 Assign7.o

# Rules to compile source code files to object code
Assign7.o: Assign7.cpp LinkedQ.h
	g++ $(CCFLAGS) -c Assign7.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o Assign7
