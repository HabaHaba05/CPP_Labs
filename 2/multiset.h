#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include <string>

class multiset
{
private:
    std::vector<std::pair<int, int>> data;

public:
    void add(int number);
    void clean();
    int size();
    void remove(int number);
    std::string toString();
};