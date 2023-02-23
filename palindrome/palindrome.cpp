#include <iostream>

int main() {
    // Variables
    bool exit = false;
    std::string user_input;
    std::string input_reversed;

    // Get input, check if it's a palindrome by reversing
    // the string and comparing it to the original
    while(!exit) {
        std::cout << "Enter a string to check if its a palindrome: ";
        std::cout << "Enter 'exit' to end the program: ";
        std::getline(std::cin, user_input);
        if(user_input == "exit") {
            exit = true;
        }
        for(int i = 0; i < user_input.length(); i++) {
            input_reversed += user_input[user_input.length() - i - 1];
        }
        if(user_input == input_reversed) {
            std::cout << "The string is a palindrome" << std::endl;
        } else {
            std::cout << "The string is not a palindrome" << std::endl;
        }
    }
    return 0;
}
