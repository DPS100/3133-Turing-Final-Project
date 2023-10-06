#ifndef TAPE_HPP
#define TAPE_HPP

#include "AlphabetWrapper.hpp"
#include "DFA.hpp"
#include <vector>

class Turing{
    private:
        DFA dfa;
        std::vector<char> tape;
        std::vector<char> negativeTape;
        int head;
        String instruction = "r";

    public:
        Turing();
        Turing(String input);
        char read();
        void write(char symbol);
        void move(bool positive);
        bool run();
        State* step();
};

#endif