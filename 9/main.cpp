#include <iostream>
#include <vector>
#include "header/myArray.hpp"
#include <algorithm>
#include <deque>
#include <list>
#include <chrono>
#include <cmath>
#include <map>
#include <set>
#include <fstream>
#include <sstream>

using namespace std;

void first()
{
    /*
    1. Susikurkite vektorių iš int testavimui ir atspausdinkite jo turinį 3 būdais: jums įprastu for
    ciklu su indeksais, for cikle naudodami tinkamo tipo iteratorius (ne auto) ir rangebased for ciklą (reikia C++11). Pasinaudodami copy algoritmu iš STL <algorithm>
    nukopojuokite savo vektorių į kitą vektorių.
    Hint: for( auto& value: v ) { ... }
    */
    cout << "----------------------------------\n";

    vector<int> x{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int>::iterator it;

    for (int i = 0; i < x.size(); i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;

    for (it = x.begin(); it != x.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    for (int i : x)
    {
        cout << i << " ";
    }
    cout << endl;

    vector<int> testCopy(10);
    copy(x.begin(), x.end(), testCopy.begin());

    for (int i : testCopy)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "----------------------------------\n";
}

void second()
{
    /*
    Parašykite iteratorių, t.y. iteratoriaus klasę, savo myArray klasei su tokiomis galimybėmis:
    a) myArray klasėje turi atsirasti metodai begin ir end, sukuriantys iteratorių.
    b) Pačiame iteratoriuje yra perkrautas dereferencinimo operatorius *
    c) prefiksinis ir postfiksinis ++ (toliau naudokite prefiksinį, kad nedarytų kopijų)
    d) palyginimo operatoriai != ir == .

    Susikurkite myArray iš tų pačių int‘ų kaip užduotyje 1.1 ir parodykite, kad identiškai
    veikia spausdinimas su jūsų iteratoriumi ir copy algoritmas
    */
    cout << "----------------------------------\n";
    MyArray<int> x;
    for (int i = 1; i <= 10; i++)
    {
        x.pushBack(i);
    }

    for (MyArray<int>::Iterator it = x.begin(); it != x.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    MyArray<int> testCopy;
    copy(x.begin(), x.end(), testCopy.begin());
    for (MyArray<int>::Iterator it = testCopy.begin(); it != testCopy.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "----------------------------------\n";
}

void insertAllVector(vector<int> &numbers, vector<int> &vector)
{
    for (int i = 0; i < numbers.size(); i++)
    {
        vector.push_back(numbers[i]);
    }
}

void insertAllDeque(vector<int> &numbers, deque<int> &deque)
{
    for (int i = 0; i < numbers.size(); i++)
    {
        deque.push_back(numbers[i]);
    }
}

void insertAllList(vector<int> &numbers, list<int> &list)
{
    for (int i = 0; i < numbers.size(); i++)
    {
        list.push_back(numbers[i]);
    }
}

void insertAllVector2(vector<int> &numbers, vector<int> &vector)
{
    for (int i = 0; i < numbers.size(); i++)
    {
        if (i % 2 == 1)
        {
            vector.push_back(numbers[i]);
        }
        else
        {
            vector.insert(vector.begin(), numbers[i]);
        }
    }
}

void insertAllDeque2(vector<int> &numbers, deque<int> &deque)
{
    for (int i = 0; i < numbers.size(); i++)
    {
        if (i % 2 == 1)
        {
            deque.push_back(numbers[i]);
        }
        else
        {
            deque.push_front(numbers[i]);
        }
    }
}

void insertAllList2(vector<int> &numbers, list<int> &list)
{
    for (int i = 0; i < numbers.size(); i++)
    {
        if (i % 2 == 1)
        {
            list.push_back(numbers[i]);
        }
        else
        {
            list.push_front(numbers[i]);
        }
    }
}

void insertAllVector3(vector<int> &numbers, vector<int> &vector)
{
    for (int newNr : numbers)
    {
        bool found = false;
        for (auto it = vector.begin(); it != vector.end(); it++)
        {
            if (*it > newNr)
            {
                vector.insert(it, newNr);
                found = true;
                break;
            }
        }
        if (!found)
        {
            vector.push_back(newNr);
        }
    }
}

void insertAllDeque3(vector<int> &numbers, deque<int> &deque)
{
    for (int newNr : numbers)
    {
        bool found = false;
        for (auto it = deque.begin(); it != deque.end(); it++)
        {
            if (*it > newNr)
            {
                deque.insert(it, newNr);
                found = true;
                break;
            }
        }
        if (!found)
        {
            deque.push_back(newNr);
        }
    }
}

void insertAllList3(vector<int> &numbers, list<int> &list)
{
    for (int newNr : numbers)
    {
        bool found = false;
        for (auto it = list.begin(); it != list.end(); ++it)
        {
            if (*it > newNr)
            {
                list.insert(it, newNr);
                found = true;
                break;
            }
        }
        if (!found)
        {
            list.push_back(newNr);
        }
    }
}

void pushBackRandomNumbers(vector<int> &vec, int N)
{
    for (int i = 0; i < N; i++)
    {
        vec.push_back(rand() % N);
    }
}

void tests()
{
    cout << "----------------------------------\n";

    using namespace std::chrono;

    vector<int> randomNumbers;
    cout << "----------------------------------\n";

    int N[]{100, 1000, 5000, 10000, 25000, 50000, 100000};

    for (int i = 0; i < 7; i++)
    {
        vector<int> mVector;
        deque<int> mDeque;
        list<int> mList;

        cout << "N= " << N[i] << ",";

        randomNumbers.clear();
        pushBackRandomNumbers(randomNumbers, N[i]);

        auto start = high_resolution_clock::now();
        insertAllVector(randomNumbers, mVector);
        auto end = high_resolution_clock::now();
        cout << "VECTOR: " << duration_cast<microseconds>(end - start).count() << ",";

        start = high_resolution_clock::now();
        insertAllDeque(randomNumbers, mDeque);
        end = high_resolution_clock::now();
        cout << "DEQUE: " << duration_cast<microseconds>(end - start).count() << ",";

        start = high_resolution_clock::now();
        insertAllList(randomNumbers, mList);
        end = high_resolution_clock::now();
        cout << "LIST: " << duration_cast<microseconds>(end - start).count() << endl;

        mVector.clear();
        mDeque.clear();
        mList.clear();
    }

    cout << "----------------------------------\n";
    for (int i = 0; i < 7; i++)
    {
        vector<int> mVector;
        deque<int> mDeque;
        list<int> mList;

        cout << "N= " << N[i] << ",";

        randomNumbers.clear();
        pushBackRandomNumbers(randomNumbers, N[i]);

        auto start = high_resolution_clock::now();
        insertAllVector2(randomNumbers, mVector);
        auto end = high_resolution_clock::now();
        cout << "VECTOR: " << duration_cast<microseconds>(end - start).count() << ",";

        start = high_resolution_clock::now();
        insertAllDeque2(randomNumbers, mDeque);
        end = high_resolution_clock::now();
        cout << "DEQUE: " << duration_cast<microseconds>(end - start).count() << ",";

        start = high_resolution_clock::now();
        insertAllList2(randomNumbers, mList);
        end = high_resolution_clock::now();
        cout << "LIST: " << duration_cast<microseconds>(end - start).count() << endl;

        mVector.clear();
        mDeque.clear();
        mList.clear();
    }

    cout << "----------------------------------\n";
    for (int i = 0; i < 4; i++)
    {
        vector<int> mVector;
        deque<int> mDeque;
        list<int> mList;

        cout << "N= " << N[i] << ",";

        randomNumbers.clear();
        pushBackRandomNumbers(randomNumbers, N[i]);

        auto start = high_resolution_clock::now();
        insertAllVector3(randomNumbers, mVector);
        auto end = high_resolution_clock::now();
        cout << "VECTOR: " << duration_cast<microseconds>(end - start).count() << ",";

        start = high_resolution_clock::now();
        insertAllDeque3(randomNumbers, mDeque);
        end = high_resolution_clock::now();
        cout << "DEQUE: " << duration_cast<microseconds>(end - start).count() << ",";

        start = high_resolution_clock::now();
        insertAllList3(randomNumbers, mList);
        end = high_resolution_clock::now();
        cout << "LIST: " << duration_cast<microseconds>(end - start).count() << endl;

        mVector.clear();
        mDeque.clear();
        mList.clear();
    }
    cout << "----------------------------------\n";
}

map<string, set<string>> readManufacturersSet(string fileName)
{
    map<string, set<string>> results;
    ifstream file(fileName);
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            stringstream stream(line);
            string car, country;
            stream >> car >> country;
            try
            {
                results.at(country).insert(car);
            }
            catch (...)
            {
                results.insert({country, {car}});
            }
        }
    }
    return results;
}

void printManufacturers(map<string, set<string>> data)
{
    for (auto it = data.begin(); it != data.end(); it++)
    {
        cout << it->first << ": ";
        for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
        {
            cout << *it2 << " ";
        }
        cout << endl;
    }
}

void cars()
{
    cout << "----------------------------------\n";
    map<string, set<string>> gamintojaiSet = readManufacturersSet("car_manufacturers.txt");
    printManufacturers(gamintojaiSet);
    cout << "----------------------------------\n";
}

int main()
{
    first();
    second();
    cars();
    tests();
};