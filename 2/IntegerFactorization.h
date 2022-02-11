#pragma once
#include "multiset.h"
#include <vector>
#include <utility>
#include <string>

class IntegerFactorization
{
private:
    multiset result;
    int number;

    void factorize();

public:
    IntegerFactorization(int number);

    void setNumber(int number);
    multiset getResult();
};