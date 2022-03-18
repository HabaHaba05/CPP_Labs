#include <iostream>
#include "header/myArray.hpp"

using namespace std;

void dummyFunc(MyArray myArray)
{
    cout << "Print array from func \n"
         << myArray << "End of dummy func\n";
}

int main()
{
    try
    {
        MyArray *myArray = new MyArray();
        cout << *myArray;

        for (int i = 0; i < 3; i++)
        {
            myArray->pushBack(i);
            cout << *myArray;
        }
        myArray->insert(1, -1);
        cout << *myArray;

        myArray->insert(0, -2);
        cout << *myArray;

        myArray->remove(myArray->getSize() - 1);
        cout << *myArray;

        myArray->remove(0);
        cout << *myArray;

        myArray->remove(1);
        cout << *myArray;

        cout << "-------------------------------\n";
        dummyFunc(MyArray());
        cout << "Main After dummy func\n";

        MyArray m2(*myArray);
        MyArray m3 = *myArray;

        cout << m2 << m3;

        delete myArray;

        cout << m2 << m3;

        m2.pushBack(99);

        cout << m2 << m3;
    }
    catch (exception &ex)
    {
        cout << ex.what();
    }
};