#pragma once
#include <iostream>

template <typename T>
class MyArray
{
private:
    T *data;
    int size;
    int capacity;

public:
    MyArray(int capacity = 2);
    ~MyArray();

    MyArray(const MyArray<T> &);

    // getters
    T getData(int index) const;
    int getSize() const;
    int getCapacity() const;
    // setters
    void setData(int index, T data);

    // methods
    void pushBack(T data);
    void insert(int index, T data);
    void remove(int index);

    // operator overloading
    T operator[](int) const;
    MyArray &operator=(const MyArray<T> &);

    template <class U>
    friend std::ostream &operator<<(std::ostream &, const MyArray<U> &);

private:
    void incSize();
    void resize();
};

#include "myArray.tpp"