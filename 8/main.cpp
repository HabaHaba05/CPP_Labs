#include <iostream>
#include <vector>
#include "header/myArray.hpp"
#include "header/Date.hpp"
#include "header/Activity.hpp"
#include "header/Team.hpp"

using namespace std;

// 1st part
template <typename T>
static void BubbleSort(std::vector<T> &data)
{
    int dataCount = data.size();
    for (int i = 0; i < dataCount - 1; i++)
    {
        for (int j = 0; j < dataCount - i - 1; j++)
        {
            if (data[j] > data[j + 1])
            {
                std::swap(data[j], data[j + 1]);
            }
        }
    }
};

template <class T>
void printVector(const std::vector<T> &data)
{

    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i] << ", ";
    }
}

void first()
{
    cout << "-------------------------------------\n";
    vector<int> intData{2, 3, 1, 4, 9, -99};
    vector<string> strData{"Medis", "Bananas", "Akmuo", "A"};

    BubbleSort(intData);
    BubbleSort(strData);
    printVector(intData);
    cout << endl;
    printVector(strData);
    cout << "\n-------------------------------------\n";
}
// 1st end

// 2nd part
void second()
{
    cout << "-------------------------------------\n";
    MyArray<int, 3> myArrayInt;
    cout << myArrayInt;

    for (int i = 0; i < 3; i++)
    {
        myArrayInt.pushBack(i);
        cout << myArrayInt;
    }

    myArrayInt.remove(0);
    cout << myArrayInt;

    MyArray<string> myArrayStr;

    myArrayStr.pushBack("vienas");
    cout << myArrayStr;
    myArrayStr.pushBack("du");
    cout << myArrayStr;
    myArrayStr.pushBack("trys");
    cout << myArrayStr;

    myArrayStr.remove(0);
    cout << myArrayStr;

    MyArray<int, 3> copy = myArrayInt;
    cout << copy;
    copy.pushBack(999);
    cout << copy;
    cout << myArrayInt;
    // copy.pushBack(9990); THIS WILL THROW ERROR

    cout << "-------------------------------------\n";
}
// 2nd end

// 4th part
void fourth()
{
    cout << "-------------------------------------\n";

    Activity *a1 = new Activity(new Date(2000), new Date(2001));
    Activity *a2 = new Activity(new Date(1999), new Date(1999, 10, 12));
    Activity *a3 = new Activity(new Date(1999), new Date(2000));
    Activity *a4 = new Activity(new Date(2999), new Date(2000, 1, 2));
    Activity *a5 = new Activity(new Date(9999), new Date(9999, 1, 2));

    Team t1("Pirma komanda"), t2("antra komanda");
    t1.addActivity(a1);
    t1.addActivity(a2);
    t1.addActivity(a5);
    t1.printActivities();

    t2.addActivity(a1);
    t2.addActivity(a3);
    t2.addActivity(a4);
    t2.printActivities();

    a1->setStartDate(new Date(0000)); // Showing that it references same object
    t1.printActivities();
    t2.printActivities();

    t2.sortActivitiesByStartDateDesc();
    t2.printActivities();

    cout << "-------------------------------------\n";
}
// 4th end

int main()
{
    first();
    second();
    fourth();
};