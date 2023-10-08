#include "AlphabetWrapper.hpp"
#include <stdexcept>

std::string* AlphabetWrapper::alphabet = nullptr;

bool AlphabetWrapper::inAlphabet(std::string s) {
    if(AlphabetWrapper::alphabet == nullptr) {
        throw std::runtime_error("Alphabet does not exist");
    }

    return AlphabetWrapper::alphabet->find(s) != std::string::npos;
}

bool AlphabetWrapper::inAlphabet(char c) {
    return inAlphabet(std::string(1, c));
}

std::string* AlphabetWrapper::getAlphabet() {
    if(AlphabetWrapper::alphabet == nullptr) {
        throw std::runtime_error("Alphabet does not exist");
    }
    return AlphabetWrapper::alphabet;
}

std::string* AlphabetWrapper::setAlphabet(std::string* alphabet) {
    AlphabetWrapper::alphabet = alphabet;
    return alphabet;
}