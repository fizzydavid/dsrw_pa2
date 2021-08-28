.PHONY: clean
main: main.o
	g++ -o main main.o

main.o: main.cc
	g++ -c main.cc -o main.o -O3 -std=c++17

clean:
	rm *.o main