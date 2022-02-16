#include "Writer.h"
#include <sstream>

template std::string Writer::vectorToString(const std::vector<int> &data);
template std::string Writer::vectorToString(const std::vector<std::string> &data);
template <class T>
std::string Writer::vectorToString(const std::vector<T> &data)
{
	std::stringstream stream;

	for (int i = 0; i < data.size(); i++)
	{
		stream << data[i] << ", ";
	}

	return stream.str();
}

template void Writer::printVector(const std::vector<int> &data);
template void Writer::printVector(const std::vector<std::string> &data);
template <class T>
void Writer::printVector(const std::vector<T> &data)
{
	std::cout << vectorToString(data) << std::endl;
}
