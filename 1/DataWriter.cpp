#include "DataWriter.h"

void DataWriter::openFile() {
	std::ofstream* of = new std::ofstream(this->filePath, std::ios::app);
	if (!of->is_open()) {
		of->open(this->filePath);
	}
	this->outputTarget = of;
}

void DataWriter::closeFile() {
	((std::ofstream*)outputTarget)->close();
}

void DataWriter::setOutputTargetConsole() {
	this->outputTarget = &std::cout;
	this->writeToFile = false;
}

void DataWriter::setOutputTargetFile(std::string path) {
	this->writeToFile = true;
	this->filePath = path;
}

template void DataWriter::printVector(const std::vector<int>& data); //Strange Trick to fix Linker problem 
template void DataWriter::printVector(const std::vector<std::string>& data);
template<class T> void DataWriter::printVector(const std::vector<T>& data) {

	if (this->writeToFile) {
		openFile();
	}

	for (int i = 0; i < data.size(); i++)
	{
		*(this->outputTarget) << data[i] << ", ";
	}
	*(this->outputTarget) << std::endl;

	if (this->writeToFile) {
		closeFile();
	}
}