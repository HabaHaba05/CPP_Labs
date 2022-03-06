init:
	if ! [ -d "./obj" ]; then mkdir obj; fi
	if ! [ -d "./bin" ]; then mkdir bin; fi
	make main

main: date.o activity.o main.o
	cd ./obj; \
	g++ date.o activity.o main.o -o ../bin/main.exe

main.o: main.cpp
	g++ -c main.cpp -o ./obj/main.o

date.o: ./src/date.cpp ./header/date.hpp
	g++ -c ./src/date.cpp -o ./obj/date.o

activity.o: ./src/activity.cpp ./header/activity.hpp
	g++ -c ./src/activity.cpp -o ./obj/activity.o

clean:
	rm ./obj/*.*  ./bin/*.*
	rmdir ./obj/ ./bin/