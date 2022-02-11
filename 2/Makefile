init:
	if ! [ -d "./obj" ]; then mkdir obj; fi
	if ! [ -d "./bin" ]; then mkdir bin; fi
	make main

main: main.o multiset.o integerfactorization.o
	cd ./obj; \
	g++ multiset.o integerfactorization.o main.o -o ../bin/main.exe

main.o: main.cpp
	g++ -c main.cpp -o ./obj/main.o

multiset.o: multiset.cpp multiset.h
	g++ -c multiset.cpp -o ./obj/multiset.o

integerfactorization.o: IntegerFactorization.cpp IntegerFactorization.h
	g++ -c IntegerFactorization.cpp -o ./obj/IntegerFactorization.o


clean:
	rmdir ./obj/ ./bin/
	