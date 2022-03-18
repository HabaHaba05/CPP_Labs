#include "../header/myArray.hpp"
#include <stdexcept>
#include <sstream>

MyArray::MyArray(int capacity)
{
    this->size = 0;
    this->capacity = capacity;
    this->data = new int[capacity];
}

MyArray::~MyArray()
{
    delete[] data;
    std::cout << "MyArray Object Destroyed\n";
}

MyArray::MyArray(const MyArray &other)
    : size(other.size), capacity(other.capacity)
{
    std::cout << "COPY\n";
    this->data = new int[this->capacity];

    for (int i = 0; i < other.size; i++)
    {
        this->data[i] = other.data[i];
    }
}

// getters
int MyArray::getData(int index) const
{
    if (index >= size || index < 0)
    {
        throw new std::range_error("When trying to use MyArray::getData(), provided Index is out of range");
    }

    return this->data[index];
}

int MyArray::getSize() const
{
    return this->size;
}

int MyArray::getCapacity() const
{
    return this->capacity;
}

// setters
void MyArray::setData(int index, int data)
{
    if (index >= size || index < 0)
    {
        throw new std::range_error("When trying to use MyArray::setData(), provided Index is out of range");
    }
    this->data[index] = data;
}

// methods
void MyArray::pushBack(int data)
{
    incSize();
    this->data[size - 1] = data;
}

void MyArray::insert(int index, int data)
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

void MyArray::remove(int index)
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

void MyArray::incSize()
{
    if (size == capacity)
    {
        resize();
    }

    this->size++;
}

void MyArray::resize()
{
    capacity *= 2;
    int *newArray = new int[capacity];

    for (int i = 0; i < size; i++)
    {
        newArray[i] = this->data[i];
    }

    delete[] this->data;

    this->data = newArray;
}

// operator overloading
MyArray &MyArray::operator=(const MyArray &other)
{
    if (this == &other)
        return *this;

    return *(new MyArray(other));
}

int MyArray::operator[](int index) const
{
    return this->getData(index);
}

std::ostream &operator<<(std::ostream &output, const MyArray &myArr)
{
    output << "MyArray (Size : " << myArr.getSize() << ", Capacity: " << myArr.getCapacity() << ")\n";
    for (int i = 0; i < myArr.getSize(); i++)
    {
        output << myArr[i] << " ";
    }
    output << "\n";
    return output;
}
