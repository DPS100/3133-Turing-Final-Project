#ifndef TAPE_HPP
#define TAPE_HPP

#include "AlphabetWrapper.hpp"
#include <vector>

class Turing{
    private:
        String* alphabet;
        std::vector<char> tape;
        std::vector<char> negativeTape;
        int head;
        

    public:
        Turing();
        Turing(String input);
        char read();
        void write(char symbol);
        void move(bool direction);
};

#endif