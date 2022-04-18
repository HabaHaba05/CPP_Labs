#include <iostream>
#include <stdexcept>
template <typename T>
MyArray<T>::MyArray(int capacity)
{
    this->size = 0;
    this->data = new T[capacity];
    this->capacity = capacity;
};

template <typename T>
MyArray<T>::~MyArray()
{
    delete[] data;
    std::cout << "MyArray Object Destroyed\n";
}

template <typename T>
MyArray<T>::MyArray(const MyArray<T> &other)
    : size(other.size), capacity(other.capacity)
{
    std::cout << "COPY\n";
    this->data = new T[this->capacity];

    for (int i = 0; i < other.size; i++)
    {
        this->data[i] = other.data[i];
    }
}

// getters
template <typename T>
T &MyArray<T>::getData(int index)
{
    return this->data[index];
}

template <typename T>
int MyArray<T>::getSize() const
{
    return this->size;
}

template <typename T>
int MyArray<T>::getCapacity() const
{
    return this->capacity;
}

// setters
template <typename T>
void MyArray<T>::setData(int index, T data)
{
    if (index >= size || index < 0)
    {
        throw new std::range_error("When trying to use MyArray::setData(), provided Index is out of range");
    }
    this->data[index] = data;
}

// methods
template <typename T>
void MyArray<T>::remove(int index)
{
    if (index < size && index >= 0)
    {
        for (int i = index; i < size - 1; i++)
        {
            setData(i, this->data[i + 1]);
        }
        this->size--;
    }
}

template <typename T>
void MyArray<T>::pushBack(T data)
{
    incSize();
    this->data[size - 1] = data;
}

template <typename T>
void MyArray<T>::insert(int index, T data)
{
    if (index >= size || index < 0)
    {
        throw new std::range_error("When trying to use MyArray::insert(), provided Index is out of range");
    }

    incSize();

    // -2 because we already increased size
    for (int i = size - 2; i >= index; i--)
    {
        setData(i + 1, this->data[i]);
    }

    this->data[index] = data;
}

template <typename T>
void MyArray<T>::incSize()
{
    if (size == capacity)
    {
        resize();
    }

    this->size++;
}

template <typename T>
void MyArray<T>::resize()
{
    capacity *= 2;
    T *newArray = new T[capacity];

    for (int i = 0; i < size; i++)
    {
        newArray[i] = this->data[i];
    }

    delete[] this->data;

    this->data = newArray;
}

// operator overloading
template <typename T>
MyArray<T> &MyArray<T>::operator=(const MyArray<T> &other)
{
    if (this == &other)
        return *this;

    return *(new MyArray(other));
}

template <typename T>
T &MyArray<T>::operator[](int index)
{
    return this->getData(index);
}

template <class T>
std::ostream &operator<<(std::ostream &output, const MyArray<T> &myArr)
{
    output << "MyArray (Size : " << myArr.getSize() << ", Capacity: " << myArr.getCapacity() << ")\n";
    for (int i = 0; i < myArr.getSize(); i++)
    {
        output << myArr[i] << " ";
    }
    output << "\n";
    return output;
}

template <typename T>
MyArray<T>::Iterator::Iterator(MyArray<T> &myArray, int position)
    : myArray(myArray), position(position) {}

template <typename T>
T &MyArray<T>::Iterator::operator*() { return myArray[position]; }

template <typename T>
T *MyArray<T>::Iterator::operator->() { return &myArray[position]; }