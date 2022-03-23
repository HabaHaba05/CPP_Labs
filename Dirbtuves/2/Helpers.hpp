#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <cctype>
#include <string>

namespace Helpers
{
    using namespace std;

    template <class T>
    string getRandom(const vector<T> &data)
    {
        // initialize random seed
        srand(time(NULL));
        int randomNumber = rand() % data.size();

        return data[randomNumber];
    };

    string &toLower(string &str)
    {
        transform(str.begin(), str.end(), str.begin(),
                  [](unsigned char c)
                  { return std::tolower(c); });
        return str;
    }

}