#pragma once
#include "Date.hpp"

class Apple
{
private:
    const int weight;
    const Date createdAt;

public:
    static int appleCount;
    static int price;

    Apple() = delete;
    Apple(int, Date);
    ~Apple();

    // getters
    int getWeight() const;
    Date getCreatedAt() const;
};