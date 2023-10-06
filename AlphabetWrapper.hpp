#ifndef ALPHABET_WRAPPER_HPP
#define ALPHABET_WRAPPER_HPP

#include <string>
typedef std::string String;

class AlphabetWrapper {
    protected:
        static String* alphabet;

    public:
        static bool inAlphabet(String s);
        static bool inAlphabet(char c);
        static String* getAlphabet();
        static String* setAlphabet(String* alphabet);
};

#endif