#pragma once
#include <iostream>

template <typename T, int MAX_SIZE = 0>
class MyArray
{
private:
    T *data;
    int size;
    int capacity;

public:
    MyArray(int capacity = 2);
    ~MyArray();

    MyArray(const MyArray<T, MAX_SIZE> &);

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
    MyArray &operator=(const MyArray<T, MAX_SIZE> &);

    template <class U, size_t S>
    friend std::ostream &operator<<(std::ostream &, const MyArray<U, S> &);

private:
    void incSize();
    void resize();
};

#include "myArray.tpp"