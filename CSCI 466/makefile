quiz.exe: quiz.o
	g++ -Wall -std=c++11 -o quiz.exe quiz.o `mysql_config --cflags --libs`
quiz.o: quiz.cc
	g++ -Wall -std=c++11 -c quiz.cc `mysql_config --cflags --libs`

clean:
	-rm quiz.o quiz.exe
