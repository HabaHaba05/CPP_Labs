#include "IntegerFactorization.h"
#include <cmath>

IntegerFactorization::IntegerFactorization(int number)
{
    this->number = number;
    factorize();
}

void IntegerFactorization::factorize()
{
    result.clean();
    int n = number;
    while (n % 2 == 0)
    {
        result.add(2);
        n = n / 2;
    }

    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            result.add(i);
            n = n / i;
        }
    }

    if (n > 2)
        result.add(n);
}

void IntegerFactorization::setNumber(int number)
{
    this->number = number;
    factorize();
}

multiset IntegerFactorization::getResult()
{
    return this->result;
}