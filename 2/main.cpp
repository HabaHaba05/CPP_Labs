#include <iostream>
#include <vector>
#include "multiset.h"
#include "IntegerFactorization.h"

int main()
{
    std::vector<int> intData{2, 3, 1, 1, 4, 4, 2, 4, 9, -99};

    multiset set;

    for (int i = 0; i < intData.size(); i++)
    {
        set.add(intData[i]);
        std::cout << set.toString() << std::endl;
        std::cout << "Size: " << set.size() << std::endl;
    }
    std::cout << "-----------------------\n";

    set.remove(4); // {value: 4,count: 3} -> {value: 4,count: 2}
    std::cout << set.toString() << std::endl;
    std::cout << "Size: " << set.size() << std::endl;

    std::cout << "-----------------------\n";

    set.remove(9); // {value: 9,count: 1} -> Obj deleted
    std::cout << set.toString() << std::endl;
    std::cout << "Size: " << set.size() << std::endl;

    IntegerFactorization factorization(12);
    std::cout << "--IntegerFactorization - 12 --\n";
    std::cout << factorization.getResult().toString() << std::endl;

    std::cout << "--IntegerFactorization - 180 --\n";
    factorization.setNumber(180);
    std::cout << factorization.getResult().toString() << std::endl;

    std::cout << "--IntegerFactorization - 11 --\n";
    factorization.setNumber(11);
    std::cout << factorization.getResult().toString() << std::endl;
}