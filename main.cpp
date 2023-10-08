#include <iostream>
#include <string>
#include "Turing.hpp"

/**
 * @brief 
 * 
 * @param arc Number of arguments
 * @param argv Array of argument
 * @return int 
 */
int main(int arc, char** argv) {
    AlphabetWrapper::setAlphabet(new std::string(""));
    Turing machine;
    std::cout << machine.getCurrentState()->getName();
    std::cout << std::endl;
    return 0;
}