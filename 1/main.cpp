#include <iostream>
#include "Writer.h"
#include "FileWriter.h"
#include "SortAlgorithms.cpp"

int main()
{
	std::vector<int> intData{2, 3, 1, 4, 9, -99};
	std::vector<std::string> strData{"Medis", "Bananas", "Akmuo", "A"};

	SortAlgorithms::BubbleSort(intData);
	SortAlgorithms::BubbleSort(strData);

	Writer consoleWriter;
	FileWriter fileWriter("./output/rez.txt");

	consoleWriter.printVector(intData);
	consoleWriter.printVector(strData);

	fileWriter.printVector(intData);
	fileWriter.printVector(strData);
}