#pragma once
#include <iostream>
#include <vector>

class Writer
{
protected:
	template <class T>
	std::string vectorToString(const std::vector<T> &);

public:
	template <class T>
	void printVector(const std::vector<T> &);
};