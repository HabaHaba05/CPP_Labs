#pragma once
#include "Writer.h"

class FileWriter : public Writer
{
private:
    std::ofstream *of = nullptr;
    std::string filePath;
    void closeFile();
    void openFile();

public:
    FileWriter(std::string);

    template <class T>
    void printVector(const std::vector<T> &);
    void setFilePath(std::string path);
};