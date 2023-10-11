#ifndef ALPHABET_WRAPPER_HPP
#define ALPHABET_WRAPPER_HPP

#include <string>

/**
 * @brief Static class to wrap the global program's alphabet
 * 
 */
class AlphabetWrapper {
    protected:
        static std::string* alphabet;

    public:
        /**
         * @brief Checks if given string is in alphabet
         * 
         * @param s
         * @return s in alphabet
         */
        static bool inAlphabet(std::string s);
        /**
         * @brief Checks if given character is in alphabet
         * 
         * @param c
         * @return c in alphabet
         */
        static bool inAlphabet(char c);
        /**
         * @brief Get the global the alphabet string
         * 
         * @return std::string* pointer to the global alphabet
         */
        static std::string* getAlphabet();
        /**
         * @brief Set the global alphabet object
         * 
         * @param alphabet Pointer to the new global alphabet
         * @return std::string* pointer to the global alphabet 
         */
        static std::string* setAlphabet(std::string* alphabet);
};

#endif