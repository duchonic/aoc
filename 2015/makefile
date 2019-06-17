all:
	g++ -std=c++11 test.cpp -o test
	./test
	rm test

test:
	g++ -std=c++17 myTest.cpp -c
	g++ -std=c++17 template.cpp -c
	g++ template.o myTest.o -o test
	./test
	rm test
	rm *.o

day22:
	g++ -std=c++17 -Wall day22.cpp -c
	g++ -std=c++17 -Wall template.cpp -c
	g++ template.o day22.o -o day22
	rm *.o
	./day22
	rm day22
