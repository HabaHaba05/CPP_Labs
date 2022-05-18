init:
	if ! [ -d "./obj" ]; then mkdir obj; fi
	if ! [ -d "./bin" ]; then mkdir bin; fi
	make main

main: item.o shoppingcart.o discount.o shop.o main.o
	cd ./obj; \
	g++ item.o shoppingcart.o discount.o shop.o main.o -o ../bin/main.exe

main.o: main.cpp
	g++ -c main.cpp -o ./obj/main.o

item.o: ./src/item.cpp ./header/item.hpp
	g++ -c ./src/item.cpp -o ./obj/item.o

shoppingcart.o: ./src/shoppingcart.cpp ./header/shoppingcart.hpp
	g++ -c ./src/shoppingcart.cpp -o ./obj/shoppingcart.o

discount.o: ./src/discount.cpp ./header/discount.hpp
	g++ -c ./src/discount.cpp -o ./obj/discount.o

shop.o: ./src/shop.cpp ./header/shop.hpp
	g++ -c ./src/shop.cpp -o ./obj/shop.o

clean:
	rm ./obj/*.*  ./bin/*.*
	rmdir ./obj/ ./bin/