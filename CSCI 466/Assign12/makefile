z1768935.exe: z1768935.o
	g++ -Wall -std=c++11 -o z1768935.exe z1768935.o `mysql_config --cflags --libs`
z1768935.o: z1768935.cc
	g++ -Wall -std=c++11 -c z1768935.cc `mysql_config --cflags --libs`

clean:
	-rm z1768935.o z1768935.exe
