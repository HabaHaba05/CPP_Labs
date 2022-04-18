#include <iostream>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iterator>
#include <chrono>
#include <functional>
#include <cmath>

using namespace std;

// g++ main.cpp -o main && ./main.exe
struct Manufacturer
{
    string brand;
    string country;
    Manufacturer(string brand, string country) : brand(brand), country(country) {}
};

vector<string> readbrands(string fileName)
{
    vector<string> results;
    ifstream file(fileName);
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            results.push_back(line);
        }
    }
    return results;
}

vector<Manufacturer> readmanufacturers(string fileName)
{
    vector<Manufacturer> results;
    ifstream file(fileName);
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            stringstream stream(line);
            string car, country;
            stream >> car >> country;
            results.push_back(Manufacturer(car, country));
        }
    }
    return results;
}

void printVector1(const vector<string> &data)
{
    for_each(data.begin(), data.end(), [](string dt)
             { cout << dt << " "; });
    cout << "\n";
}

void printVector2(const vector<string> &data)
{
    ostream_iterator<string> res(cout, " ");

    copy(data.begin(), data.end(), res);
    cout << "\n";
}

void removeDuplicates1(vector<string> data)
{
    for (auto it = data.begin(); it != data.end(); it++)
    {
        for (auto it2 = it + 1; it2 != data.end(); it2++)
        {
            if (*it == *it2)
            {
                data.erase(it2);
                it2--;
            }
        }
    }
    printVector1(data);
}

void removeDuplicates2(vector<string> data)
{
    using namespace std::chrono;

    auto start = high_resolution_clock::now();
    set<string> mSet(data.begin(), data.end());
    vector<string> mVector(mSet.begin(), mSet.end());
    auto end = high_resolution_clock::now();
    cout << "SET: " << duration_cast<microseconds>(end - start).count() << " - ";
    printVector1(mVector);

    start = high_resolution_clock::now();
    unordered_set<string> mSet1(data.begin(), data.end());
    vector<string> mVector1(mSet.begin(), mSet.end());
    end = high_resolution_clock::now();
    cout << "U_SET: " << duration_cast<microseconds>(end - start).count() << " - ";
    printVector1(mVector1);
}

void removeDuplicates3(vector<string> data)
{
    sort(data.begin(), data.end());
    auto it = unique(data.begin(), data.end());
    data.resize(distance(data.begin(), it));
    printVector1(data);
}

void sort1(vector<string> data)
{
    sort(data.begin(), data.end());
    printVector1(data);
}

void sort2(vector<string> data)
{
    auto func = [](const string &a, const string &b)
    {
        if (a.length() == b.length())
        {
            return a < b;
        }

        return a.length() < b.length();
    };

    sort(data.begin(), data.end(), func);
    printVector1(data);
}

void copyIf1(vector<string> data, char startsWith)
{
    for (auto it = data.begin(); it != data.end(); it++)
    {
        if ((*it)[0] != startsWith)
        {
            data.erase(it);
            it--;
        }
    }
    printVector1(data);
}

void copyIf2(vector<string> data, char startsWith)
{
    struct copy_condition
    {
        char startsWith;
        copy_condition(char startsWith) : startsWith(startsWith) {}
        bool operator()(const string &a)
        {
            return a[0] == startsWith;
        }
    };

    vector<string> res(data.size());
    auto it = copy_if(data.begin(), data.end(), res.begin(), copy_condition(startsWith));
    res.resize(distance(res.begin(), it));
    printVector1(res);
}

void copyIf2(vector<string> data, string startsWith)
{
    struct copy_condition
    {
        string startsWith;
        copy_condition(string startsWith) : startsWith(startsWith) {}
        bool operator()(const string &a)
        {
            return a.find(startsWith) == 0;
        }
    };

    vector<string> res(data.size());
    auto it = copy_if(data.begin(), data.end(), res.begin(), copy_condition(startsWith));
    res.resize(distance(res.begin(), it));
    printVector1(res);
}

void transform1(vector<string> data)
{
    auto func = [](const string &a, const string &b)
    {
        if (a.length() == b.length())
        {
            return a < b;
        }

        return a.length() < b.length();
    };

    transform(data.begin(), data.end(), data.begin(), [](string a)
              { transform(a.begin(), a.end(), a.begin(),
                          [](unsigned char c)
                          { return std::tolower(c); });
                return a; });
    printVector1(data);
}

void removeIf1(vector<string> data)
{
    auto it = remove_if(data.begin(), data.end(), [data](const string &a)
                        { 
                            int count = count_if(data.begin(), data.end(), [a](const string &b)
                                               { return a == b; });
                            return count != 1; });
    data.resize(distance(data.begin(), it));
    printVector1(data);
}

void sortManufactures(vector<Manufacturer> data, string byProperty)
{
    if (byProperty == "brand")
    {
        sort(data.begin(), data.end(), [](const Manufacturer &obj1, const Manufacturer &obj2)
             { return obj1.brand < obj2.brand; });
    }
    else if (byProperty == "country")
    {
        sort(data.begin(), data.end(), [](const Manufacturer &obj1, const Manufacturer &obj2)
             { return obj1.country < obj2.country; });
    }
    for_each(data.begin(), data.end(), [](Manufacturer dt)
             { cout << dt.country << " " << dt.brand << endl; });
}

int main()
{
    vector<string> brands = readbrands("car_brands.txt");
    cout << "--------------2.1----------------\n";
    printVector1(brands);
    cout << "--------------2.2----------------\n";
    printVector2(brands);
    cout << "--------------3.1----------------\n";
    removeDuplicates1(brands);
    cout << "--------------3.2----------------\n";
    removeDuplicates2(brands);
    cout << "--------------3.3----------------\n";
    removeDuplicates3(brands);
    cout << "--------------4.1----------------\n";
    sort1(brands);
    cout << "--------------4.2----------------\n";
    sort2(brands);
    cout << "--------------5.1----------------\n";
    copyIf1(brands, 'A');
    cout << "--------------5.2----------------\n";
    copyIf2(brands, 'A');
    cout << "--------------6.1----------------\n";
    copyIf2(brands, "Vo");
    cout << "--------------7.1----------------\n";
    transform1(brands);
    cout << "--------------8.1----------------\n";
    string arg1 = "Volkswagen";
    cout << count_if(brands.begin(), brands.end(), [arg1](const string &a)
                     { return a == arg1; })
         << endl;
    cout << "--------------8.2----------------\n";
    int arg2 = 7;
    cout << count_if(brands.begin(), brands.end(), [arg2](const string &a)
                     { return a.length() == arg2; })
         << endl;
    cout << "--------------9.1----------------\n";
    removeIf1(brands);

    cout << "--------------10.1----------------\n";
    vector<Manufacturer> manufactures = readmanufacturers("car_manufacturers.txt");
    sortManufactures(manufactures, "brand");
    cout << endl;
    sortManufactures(manufactures, "country");

    cout << "-------------------------------\n";
    cout << "-------------------------------\n";
    cout << "--------------2----------------\n";
    vector<int> numbers = {3, 5};
    cout << "Suma: " << accumulate(numbers.begin(), numbers.end(), 0) << endl;
    cout << "Daugyba: " << accumulate(numbers.begin(), numbers.end(), 1, multiplies<int>{}) << endl;
    cout << "Cust1: " << sqrt(accumulate(numbers.begin(), numbers.end(), 0, [](int acc, int number)
                                         { return acc + number * number; }))
         << endl;
    cout << "Cust2: " << accumulate(numbers.begin(), numbers.end(), string(), [](string acc, int number)
                                    { if(acc == ""){
                                    return to_string(number) + "^2";
                                  }else{
                                      return acc + " + " + to_string(number) + "^2";
                                  } })
         << endl;

    return 0;
}