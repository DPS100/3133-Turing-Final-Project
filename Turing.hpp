#ifndef TAPE_HPP
#define TAPE_HPP

#include "AlphabetWrapper.hpp"
#include "DFA.hpp"
#include <vector>
#include <string>

class Turing : public DFA{
    private:
        std::vector<char> tape;
        std::vector<char> negativeTape;
        int head;

    public:
        Turing();
        Turing(std::string input);
        Turing(std::vector<State*> states);
        Turing(std::vector<State*> states, std::string input);
        /**
         * @brief Read the current symbol the head of the machine is pointing to
         * 
         * @return char 
         */
        char read();
        /**
         * @brief Write a symbol to the tape that the head of the machine is pointing to
         * 
         * @param symbol 
         */
        void write(char symbol);
        /**
         * @brief Move the head of the tape
         * 
         * @param positive Moves in the positive direction if true, negative direction if false
         */
        void move(bool positive);
        /**
         * @brief Run the turing machine until a halt occurs.
         * @warning Halting is not garaunteed. May hang program.
         * 
         * @return true 
         * @return false 
         */
        bool run();
        /**
         * @brief Advance one step on the turing machine, and return the current state
         * 
         * @return State* 
         */
        State* step();
};

#endif