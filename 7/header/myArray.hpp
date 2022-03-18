#pragma once
#include <iostream>

class MyArray
{
private:
    int *data;
    int size;
    int capacity;

public:
    MyArray(int capacity = 2);
    ~MyArray();

    MyArray(const MyArray &);

    // getters
    int getData(int index) const;
    int getSize() const;
    int getCapacity() const;
    // setters
    void setData(int index, int data);

    // methods
    void pushBack(int data);
    void insert(int index, int data);
    void remove(int index);

    // operator overloading
    int operator[](int) const;
    MyArray &operator=(const MyArray &);
    friend std::ostream &operator<<(std::ostream &, const MyArray &);

private:
    void incSize();
    void resize();
};