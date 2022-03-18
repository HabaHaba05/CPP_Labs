init:
	if ! [ -d "./obj" ]; then mkdir obj; fi
	if ! [ -d "./bin" ]; then mkdir bin; fi
	make main

main: main.o myArray.o
	cd ./obj; \
	g++ myArray.o main.o -o ../bin/main.exe

main.o: main.cpp
	g++ -c main.cpp -o ./obj/main.o

myArray.o: ./src/myArray.cpp ./header/myArray.hpp
	g++ -c ./src/myArray.cpp -o ./obj/myArray.o

clean:
	rm ./obj/*.*  ./bin/*.*
	rmdir ./obj/ ./bin/