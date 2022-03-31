#include <iostream>
#include <stdexcept>
template <typename T, int MAX_SIZE>
MyArray<T, MAX_SIZE>::MyArray(int capacity)
{
    this->size = 0;
    this->data = new T[capacity];

    if (MAX_SIZE != 0)
    {
        this->capacity = MAX_SIZE;
    }
    else
    {
        this->capacity = capacity;
    }
};

template <typename T, int MAX_SIZE>
MyArray<T, MAX_SIZE>::~MyArray()
{
    delete[] data;
    std::cout << "MyArray Object Destroyed\n";
}

template <typename T, int MAX_SIZE>
MyArray<T, MAX_SIZE>::MyArray(const MyArray<T, MAX_SIZE> &other)
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
template <typename T, int MAX_SIZE>
T MyArray<T, MAX_SIZE>::getData(int index) const
{
    if (index >= size || index < 0)
    {
        throw new std::range_error("When trying to use MyArray::getData(), provided Index is out of range");
    }

    return this->data[index];
}

template <typename T, int MAX_SIZE>
int MyArray<T, MAX_SIZE>::getSize() const
{
    return this->size;
}

template <typename T, int MAX_SIZE>
int MyArray<T, MAX_SIZE>::getCapacity() const
{
    return this->capacity;
}

// setters
template <typename T, int MAX_SIZE>
void MyArray<T, MAX_SIZE>::setData(int index, T data)
{
    if (index >= size || index < 0)
    {
        throw new std::range_error("When trying to use MyArray::setData(), provided Index is out of range");
    }
    this->data[index] = data;
}

// methods
template <typename T, int MAX_SIZE>
void MyArray<T, MAX_SIZE>::remove(int index)
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

template <typename T, int MAX_SIZE>
void MyArray<T, MAX_SIZE>::pushBack(T data)
{
    incSize();
    this->data[size - 1] = data;
}

template <typename T, int MAX_SIZE>
void MyArray<T, MAX_SIZE>::insert(int index, T data)
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

template <typename T, int MAX_SIZE>
void MyArray<T, MAX_SIZE>::incSize()
{
    if (size == capacity)
    {
        resize();
    }

    this->size++;
}

template <typename T, int MAX_SIZE>
void MyArray<T, MAX_SIZE>::resize()
{
    if (MAX_SIZE != 0 && capacity == MAX_SIZE)
    {
        throw new std::runtime_error("Array has reached MAX SIZE");
    }

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
template <typename T, int MAX_SIZE>
MyArray<T, MAX_SIZE> &MyArray<T, MAX_SIZE>::operator=(const MyArray<T, MAX_SIZE> &other)
{
    if (this == &other)
        return *this;

    return *(new MyArray(other));
}

template <typename T, int MAX_SIZE>
T MyArray<T, MAX_SIZE>::operator[](int index) const
{
    return this->getData(index);
}

template <class T, int MAX_SIZE>
std::ostream &operator<<(std::ostream &output, const MyArray<T, MAX_SIZE> &myArr)
{
    output << "MyArray (Size : " << myArr.getSize() << ", Capacity: " << myArr.getCapacity() << ")\n";
    for (int i = 0; i < myArr.getSize(); i++)
    {
        output << myArr[i] << " ";
    }
    output << "\n";
    return output;
}