#include "multiset.h"

void multiset::add(int number)
{
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i].first == number)
        {
            data[i].second++;
            return;
        }
    }
    data.push_back(std::make_pair(number, 1));
}

int multiset::size()
{
    int cnt = 0;
    for (int i = 0; i < data.size(); i++)
    {
        cnt += data[i].second;
    }
    return cnt;
}

void multiset::remove(int number)
{
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i].first == number)
        {
            data[i].second--;
            if (data[i].second == 0)
            {
                data.erase(data.begin() + i);
            }
            return;
        }
    }
}

void multiset::clean()
{
    data.erase(data.begin(), data.end());
}

std::string multiset::toString()
{
    std::string str = "[";

    for (int i = 0; i < data.size(); i++)
    {

        str.append("{value: " + std::to_string(data[i].first) + ",");
        str.append("count: " + std::to_string(data[i].second) + "}");

        if (i != data.size() - 1)
        {
            str.append(", ");
        }
    }
    str.append("]");
    return str;
}