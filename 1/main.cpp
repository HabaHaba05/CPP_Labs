#include <iostream>
#include "DataWriter.h"
#include "SortAlgorithms.cpp"

int main()
{
	std::vector<int> intData {2, 3, 1, 4, 9, -99 };
	std::vector<std::string> strData{ "Medis","Bananas","Akmuo","A" };

	SortAlgorithms::BubbleSort(intData);
	SortAlgorithms::BubbleSort(strData);

	DataWriter dw;
	dw.printVector(intData);
	dw.printVector(strData);
	
	dw.setOutputTargetFile("./output/rez.txt");
	dw.printVector(intData);
	dw.printVector(strData);
}