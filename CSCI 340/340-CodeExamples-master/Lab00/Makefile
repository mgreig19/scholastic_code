.DEFAULT_GOAL := lab00.exe

lab00.o: lab00.cc
	g++ -c lab00.cc -Wall -std=c++11

lab00.exe: lab00.o
	g++ -o lab00.exe lab00.o -Wall -std=c++11

clean:
	rm *.o lab00.exe