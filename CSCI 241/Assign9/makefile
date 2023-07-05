#
# PROGRAM:    polymorph
# PROGRAMMER: Mason Greig
# LOGON ID:   z1768935
# DUE: 11/29/2016

# Compiler variables
CCFLAGS = -ansi -Wall -std=c++11

# Rule to link object code files to create executable file
polymorph: assign9.o shape.o circle.o rectangle.o triangle.o
	g++ $(CCFLAGS) -o polymorph assign9.o shape.o circle.o rectangle.o triangle.o

# Rules to compile source code files to object code
assign9.o: assign9.cpp shape.h circle.h rectangle.h triangle.h
	g++ $(CCFLAGS) -c assign9.cpp

shape.o: shape.cpp shape.h
	g++ $(CCFLAGS) -c shape.cpp

circle.o: circle.cpp circle.h
	g++ $(CCFLAGS) -c circle.cpp

rectangle.o: rectangle.cpp rectangle.h
	g++ $(CCFLAGS) -c rectangle.cpp

triangle.o: triangle.cpp triangle.h
	g++ $(CCFLAGS) -c triangle.cpp

circle.h: shape.h
rectangle.h: shape.h
triangle.h: shape.h

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o polymorph
