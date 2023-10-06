#include "AlphabetWrapper.hpp"
#include <stdexcept>


bool AlphabetWrapper::inAlphabet(String s) {
    if(alphabet == nullptr) {
        throw std::runtime_error("Alphabet does not exist");
    }

    return alphabet->find(s) != String::npos;
}

bool AlphabetWrapper::inAlphabet(char c) {
    return inAlphabet(String(1, c));
}

String* AlphabetWrapper::getAlphabet() {
    if(alphabet == nullptr) {
        throw std::runtime_error("Alphabet does not exist");
    }
    return alphabet;
}

String* AlphabetWrapper::setAlphabet(String* alphabet) {
    AlphabetWrapper::alphabet = alphabet;
    return alphabet;
}