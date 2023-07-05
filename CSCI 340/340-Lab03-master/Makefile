.DEFAULT_GOAL := lab03.exe

lab03.o: lab03.cc
	g++ -c lab03.cc -Wall -std=c++11

lab03.exe: lab03.o
	g++ -o lab03.exe lab03.o -Wall -std=c++11

clean:
	rm *.o lab03.exe