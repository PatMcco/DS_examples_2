#include <iostream>
#include <cstring>

int factorial(int num) {
    // end the recursion
    if(num == 1) {
        return 1;
    }
    return num * factorial(num - 1);
}
bool is_palindrome_recursive(char* input, int len) {
    // no word or a one-letter word is a palindrome
    if (len <= 1) {
        return true;
    }
    // check if the first and last letters are the same
    if (input[0] == input[len - 1]) {
        // if they are, check the next letters
        return is_palindrome_recursive(&input[1], len - 2);
    }
    return false;
}

int main() {
    constexpr int BUFFER_SIZE = 80;
    char buffer[BUFFER_SIZE];

    std::cout << "Enter a word to check if it's a palindrome: ";
    std::cin.getline(buffer, BUFFER_SIZE);

    if (is_palindrome_recursive(buffer, strlen(buffer))) {
std::cout << buffer << " is a palindrome" << std::endl;
    } else {
        std::cout << buffer << " is not a palindrome" << std::endl;
    }


    // a factorial is a mathematical expression
    // that is the product of an integer and all
    // the integers below it

    // 5! = 5 * 4 * 3 * 2 * 1 = 120
    // 4! = 4 * 3 * 2 * 1 = 24
    // 3! = 3 * 2 * 1 = 6
    // etc..

    std::cout << "5! = " << factorial(5) << std::endl;

    return 0;
}