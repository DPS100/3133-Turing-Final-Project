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
    AlphabetWrapper::setAlphabet(new std::string("01#"));
    Turing machine;
    std::cout << machine.getCurrentState()->getName() << std::endl;
    std::cout << machine.getCurrentState()->next('e').first << machine.getCurrentState()->next('e').second;
    std::cout << std::endl;
    return 0;
}