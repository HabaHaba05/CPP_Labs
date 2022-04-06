init:
	if ! [ -d "./obj" ]; then mkdir obj; fi
	if ! [ -d "./bin" ]; then mkdir bin; fi
	make main

main: main.o
	cd ./obj; \
	g++ main.o -o ../bin/main.exe

main.o: main.cpp
	g++ -c main.cpp -o ./obj/main.o


clean:
	rm ./obj/*.*  ./bin/*.*
	rmdir ./obj/ ./bin/