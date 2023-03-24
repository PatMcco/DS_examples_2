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

void bubble_sort(std::span<int> array) {
    for (int i = 0; i < array.size() - 2; i++) {
        for (int j = 0; j < array.size() - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                int temp =  array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }
}

int main() {

    auto nums = std::to_array({3,6,8,10,5,9,4,1,2,7});

    std::cout << "Before sorting..." << std::endl;
    dump_array(nums);

    bubble_sort(nums);

    std::cout << "After Sorting..." << std::endl;
    dump_array(nums);

    return 0;
}