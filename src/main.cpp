#include <iostream>
#include <string>
#include <fstream>
#include "Turing.hpp"

void trimString(std::string* string, int trimSize);

/**
 * @brief 
 * 
 * @param arc Number of arguments
 * @param argv Array of argument
 * @return int 
 */
int main(int argc, char** argv) {
    int delayMs = 0;
    bool prettyPrinting = false;
    std::string filename;

    // Read args
    for(int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        if(arg == "-h" || arg == "--help") {
            std::cout << "Usage: " << argv[0] << " [options]" << std::endl;
            std::cout << "Options:" << std::endl;
            std::cout << "  -h, --help   Show help message" << std::endl;
            std::cout << "  -i, --input  Path to target input file. See README for more information on how this is formatted." << std::endl;
            std::cout << "  -p, --print  Enable pretty printing. Output progress of simulated Turing machine to the console." << std::endl;
            std::cout << "  -d, --delay  Delay time in ms between transition between states. Automatically enables pretty printing." << std::endl;
            return 1;
        } else if(arg == "-i" || arg == "--input") {
            filename = argv[++i];
        } else if(arg == "-d" || arg == "--delay") {
            delayMs = std::stoi(argv[++i]);
            prettyPrinting = true;
        } else if(arg == "-p" || arg == "--print") {
            prettyPrinting = true;    
        } else {
            std::cout << "Unknown option \"" << arg << "\". Use \"-h\" or see the readme for help." << std::endl;
            return 1; 
        }
    }

    // Read input file
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open the input file. Run with the -h flag for more options." << std::endl;
        return 1;
    }

    // Temporarily set alphabet - avoids states being unhappy with alphabet not existing
    std::string alphabet;
    AlphabetWrapper::setAlphabet(&alphabet);

    // Read states at top of file
    std::vector<State*> states;
    std::string state;
    std::getline(inputFile, state);
    int emptyLineLength = state.length();
    while(std::getline(inputFile, state)) {
        if(state.length() == emptyLineLength) { // Empty line
            break;
        }
        // Remove the last character from the state
        trimString(&state, emptyLineLength);
        // std::cout << state << std::endl;
        states.push_back(new State(state));
    }

    // Read language
    std::getline(inputFile, alphabet);
    trimString(&alphabet, emptyLineLength);
    // std::cout << "Alphabet: " << alphabet << std::endl;
    AlphabetWrapper::setAlphabet(&alphabet);

    // Read starting tape
    std::string tape;
    std::getline(inputFile, tape);
    trimString(&tape, emptyLineLength);
    // std::cout << "Tape: " << tape << std::endl;

    // Read transitions
    std::string transitionStrings[alphabet.length()];
    int index = 0;
    if(alphabet.length() == 0) {
        std::cerr << "Alphabet was read with length zero. Did you remember to include a blank line at the top of the input file?" << std::endl;
        return 1;
    }
    while(inputFile >> transitionStrings[index % alphabet.length()]) {
        // int transitionStringIndex = index % alphabet.length();
        if(index % alphabet.length() == alphabet.length() - 1) {
            // std::cout << "Setting state " << states.at(index / alphabet.length())->getName() << std::endl;
            std::map<char, Transition> transitions;
            for(int i = 0; i < alphabet.length(); i++) {
                char symbol = alphabet.at(i);
                int digitIndex = 0;
                while (digitIndex < transitionStrings[i].length() && isdigit(transitionStrings[i][digitIndex])) {
                    digitIndex++;
                }
                int targetState = stoi(transitionStrings[i].substr(0, digitIndex)) - 1;
                std::string instruction = transitionStrings[i].substr(digitIndex);
                // std::cout << targetState << instruction << std::endl;
                if(targetState >= states.size()) {
                    std::clog << "Error reading input file: Number of states defined exceeds number of states declared." << std::endl;
                    return 1;
                }
                transitions.emplace(symbol, Transition(instruction, states.at(targetState)));
                // std::cout << "When reading symbol " << symbol << ", take action " << instruction << " and move to state " << targetState << ": " << states.at(targetState)->getName() << std::endl;
            }
            states.at(index / alphabet.length())->setTransitions(transitions);
        }
        index++;
    }

    // Main program
    Turing machine(states, tape);
    bool result = machine.run(delayMs, prettyPrinting);
    std::cout << "\nTuring machine halted with code: " << (result ? " Accept " : "Decline") << std::endl;
    return 0;
}

void trimString(std::string* string, int trimSize) {
    *string = string->substr(0, string->length() - trimSize);
}