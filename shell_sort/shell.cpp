#include <iostream>
#include <array>
#include <span>
#include <iomanip>

void dump_array(std::span<int> array) {
    for(auto num : array) {
        std::cout << std::setw(3)<< num;
    }
    std::cout << std::endl;
}

void shell_sort(std::span<int> array) {
    // determine gap size, starting at array size / 2
    // until gap is 1
    for (auto gap = array.size() / 2; gap > 0; gap /= 2) {
        // sort the smaller arrays
        for (auto start = 0; start < gap; ++start) {
            // use the insertion sort each small array
            for (auto i = start + gap; i < array.size(); i += gap) {
                // store the current value for possible move
                auto temp = array[i];
                // shuffle values greater than the current value
                auto j = 1;
                for(; j >= gap && temp < array[j - gap]; j -= gap) {
                    array[j] = array[j - gap];
                }
                // put the current value where he should go
                array[j] = temp;
            }
        }
    }
}

int main() {

    auto nums = std::to_array({3,6,8,10,5,9,4,1,2,7});

    std::cout << "Before sorting..." << std::endl;
    dump_array(nums);

    shell_sort(nums);

    std::cout << "After Sorting..." << std::endl;
    dump_array(nums);

    return 0;
}