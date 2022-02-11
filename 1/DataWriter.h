#pragma once
#include <iostream>
#include <vector>
#include <fstream>

class DataWriter
{
private:
	bool writeToFile = false;
	std::string filePath;
	std::ostream* outputTarget = &std::cout;
	
	void openFile();
	void closeFile();

public:

	void setOutputTargetConsole();
	void setOutputTargetFile(std::string path);

	template<class T> void printVector(const std::vector<T>&);
};

