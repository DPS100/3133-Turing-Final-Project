#ifndef ALPHABET_WRAPPER_HPP
#define ALPHABET_WRAPPER_HPP

#include <string>

class AlphabetWrapper {
    protected:
        static std::string* alphabet;

    public:
        static bool inAlphabet(std::string s);
        static bool inAlphabet(char c);
        static std::string* getAlphabet();
        static std::string* setAlphabet(std::string* alphabet);
};

#endif