init:
	if ! [ -d "./obj" ]; then mkdir obj; fi
	if ! [ -d "./bin" ]; then mkdir bin; fi
	make main

main: helpers.o date.o apple.o appleTree.o basket.o picker.o main.o
	cd ./obj; \
	g++ helpers.o date.o apple.o appleTree.o basket.o picker.o main.o -o ../bin/main.exe

main.o: main.cpp
	g++ -c main.cpp -o ./obj/main.o

date.o: ./src/date.cpp ./header/date.hpp
	g++ -c ./src/date.cpp -o ./obj/date.o

apple.o: ./src/apple.cpp ./header/apple.hpp
	g++ -c ./src/apple.cpp -o ./obj/apple.o

appleTree.o: ./src/appleTree.cpp ./header/appleTree.hpp
	g++ -c ./src/appleTree.cpp -o ./obj/appleTree.o

basket.o: ./src/basket.cpp ./header/basket.hpp
	g++ -c ./src/basket.cpp -o ./obj/basket.o

picker.o: ./src/picker.cpp ./header/picker.hpp
	g++ -c ./src/picker.cpp -o ./obj/picker.o

helpers.o: ./src/helpers.cpp
	g++ -c ./src/helpers.cpp -o ./obj/helpers.o

clean:
	rm ./obj/*.*  ./bin/*.*
	rmdir ./obj/ ./bin/