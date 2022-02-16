init:
	if ! [ -d "./obj" ]; then mkdir obj; fi
	if ! [ -d "./bin" ]; then mkdir bin; fi
	if ! [ -d "./output" ]; then mkdir output; fi
	make main

main: main.o sortalgorithms.o writer.o filewriter.o
	cd ./obj; \
	g++ sortalgorithms.o writer.o filewriter.o main.o -o ../bin/main.exe

main.o: main.cpp
	g++ -c main.cpp -o ./obj/main.o

sortalgorithms.o: sortalgorithms.cpp
	g++ -c sortalgorithms.cpp -o ./obj/sortalgorithms.o

writer.o: writer.cpp writer.h
	g++ -c writer.cpp -o ./obj/writer.o

filewriter.o: filewriter.cpp filewriter.h
	g++ -c filewriter.cpp -o ./obj/filewriter.o

clean:
	rm ./obj/*.*  ./bin/*.* ./output/*.* 
	rmdir ./obj/ ./bin/ ./output/ 
	