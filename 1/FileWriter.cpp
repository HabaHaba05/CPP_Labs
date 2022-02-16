#include "FileWriter.h"
#include <fstream>

FileWriter::FileWriter(std::string filePath)
{
    this->filePath = filePath;
}

void FileWriter::openFile()
{
    of = new std::ofstream(this->filePath, std::ios::app);
    if (!of->is_open())
    {
        of->open(this->filePath);
    }
}

void FileWriter::closeFile()
{
    if (of != nullptr)
    {
        of->close();
    }
}

void FileWriter::setFilePath(std::string path)
{
    closeFile();
    of = nullptr;
    filePath = path;
}

template void FileWriter::printVector(const std::vector<int> &data);
template void FileWriter::printVector(const std::vector<std::string> &data);
template <class T>
void FileWriter::printVector(const std::vector<T> &data)
{

    openFile();

    *of << vectorToString(data) << std::endl;

    closeFile();
}