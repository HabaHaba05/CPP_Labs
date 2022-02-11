init:
	if ! [ -d "./obj" ]; then mkdir obj; fi
	if ! [ -d "./bin" ]; then mkdir bin; fi
	if ! [ -d "./output" ]; then mkdir output; fi
	make main

main: main.o sortalgorithms.o datawriter.o
	cd ./obj; \
	g++ sortalgorithms.o datawriter.o main.o -o ../bin/main.exe

main.o: main.cpp
	g++ -c main.cpp -o ./obj/main.o

sortalgorithms.o: sortalgorithms.cpp
	g++ -c sortalgorithms.cpp -o ./obj/sortalgorithms.o

datawriter.o: datawriter.cpp datawriter.h
	g++ -c datawriter.cpp -o ./obj/datawriter.o

clean:
	rm ./obj/*.*  ./bin/*.* ./output/*.* 
	rmdir ./obj/ ./bin/ ./output/ 
	