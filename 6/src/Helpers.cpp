#include <vector>

template <typename T>
void clearVectorContent(std::vector<T> &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        delete a[i];
    }
    a.clear();
}
