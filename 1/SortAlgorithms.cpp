#include <algorithm>
#include <vector>

namespace SortAlgorithms {

    template <typename T>
    static void BubbleSort(std::vector<T>& data) {
        int dataCount = data.size();
        for (int i = 0; i < dataCount - 1; i++) {
            for (int j = 0; j < dataCount - i - 1; j++) {
                if (data[j] > data[j + 1]) {
                    std::swap(data[j], data[j + 1]);
                }
            }
        }
    };
}