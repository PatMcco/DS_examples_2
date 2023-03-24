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

void insertion_sort(std::span<int> array) {
    for (auto i = 1; i < array.size(); ++i) {
        // store the current value for possible move
        auto temp = array[i];

        // shuffle values greater than the current value
        auto j = 1;
        for(; j > 0 && temp < array[j - 1]; j--) {
            array[j] = array[j - 1];
        }

        // put the current value where he should go
        array[j] = temp;
    }
}

int main() {

    auto nums = std::to_array({3,6,8,10,5,9,4,1,2,7});

    std::cout << "Before sorting..." << std::endl;
    dump_array(nums);

    insertion_sort(nums);

    std::cout << "After Sorting..." << std::endl;
    dump_array(nums);

    return 0;
}