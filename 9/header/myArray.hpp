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
    class Iterator
    {
    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = T *;
        using reference = T &;

    private:
        MyArray<T> &myArray;
        int position;

    public:
        Iterator(MyArray<T> &myArray, int position)
            : myArray(myArray), position(position) {}

        T &operator*() { return myArray[position]; }
        T *operator->() { return &myArray[position]; }

        Iterator &operator++()
        {
            position++;
            return *this;
        }

        Iterator operator++(int)
        {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }
        friend bool operator==(const Iterator &a, const Iterator &b) { return a.myArray[a.position] == b.myArray[b.position]; };
        friend bool operator!=(const Iterator &a, const Iterator &b) { return a.myArray[a.position] != b.myArray[b.position]; };
    };

    MyArray(int capacity = 2);
    ~MyArray();

    MyArray(const MyArray<T> &);

    Iterator begin() { return Iterator(*this, 0); }
    Iterator end() { return size == 0 ? Iterator(*this, capacity) : Iterator(*this, size); }

    // getters
    T &getData(int index);
    int getSize() const;
    int getCapacity() const;
    // setters
    void setData(int index, T data);

    // methods
    void pushBack(T data);
    void insert(int index, T data);
    void remove(int index);

    // operator overloading
    T &operator[](int);
    MyArray &operator=(const MyArray<T> &);

    template <typename U>
    friend std::ostream &operator<<(std::ostream &, const MyArray<U> &);

private:
    void incSize();
    void resize();
};
#include "myArray.tpp"