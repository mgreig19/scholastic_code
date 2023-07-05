# PROGRAM:    Assignment 9
# PROGRAMMER: Mason Greig
# LOGON ID:   z1768935
# DATE DUE:   12/2/2016
#

# Compiler variables
CCFLAGS = -ansi -Wall -std=c++11

# Rule to link object code files to create executable file
z1768935: z1768935.o
	g++ $(CCFLAGS) -o z1768935 z1768935.o

# Rules to compile source code files to object code
z1768935.o: z1768935.cxx
	g++ $(CCFLAGS) -c z1768935.cxx

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o z1768935

