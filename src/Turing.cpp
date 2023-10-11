#include "Turing.hpp"

#include <iostream>
#include <chrono>
#include <thread>

Turing::Turing(std::string input) :
    head(0),
    tape(std::vector<char>(input.size())){
    populateTape(input);
}

Turing::Turing() {
    *this = Turing("");
}

Turing::Turing(std::vector<State*> states, std::string input) :
    DFA(states),
    tape(std::vector<char>(input.size())){
    populateTape(input);
}

Turing::Turing(std::vector<State*> states, State* accept, State* decline) :
    DFA(states, accept, decline) {
    populateTape("");
}

Turing::Turing(std::vector<State*> states, State* accept, State* decline, std::string input) :
    DFA(states, accept, decline) {
    populateTape(input);
}

char Turing::read() {
    // If head is out of range, write the first (presumably blank) character
    if(head >= 0) {
        if(head == tape.size()) {
            tape.push_back(AlphabetWrapper::getAlphabet()->at(0));
        }
        return tape.at(head);
    } else {
        if(-head - 1 == negativeTape.size()) {
            negativeTape.push_back(AlphabetWrapper::getAlphabet()->at(0));
        }
        return negativeTape.at(-head - 1);
    }
}

void Turing::write(char symbol) {
    if(head >= 0) {
        tape.reserve(head);
        tape.at(head) = symbol;
    } else {
        negativeTape.reserve(-head - 1);  
        negativeTape.at(-head - 1) = symbol;
    }
}

void Turing::move(bool positive) {
    positive ? head++ : head--;
}

bool Turing::run() {
    return run(0, false);
}

bool Turing::run(int msDelay) {
    return run(msDelay, false);
}

bool Turing::run(bool print) {
    return run(0, print);
}

bool Turing::run(int msDelay, bool print) {
    while(getCurrentState() != accept && getCurrentState() != decline) {
        if(msDelay != 0) std::this_thread::sleep_for(std::chrono::milliseconds(msDelay));
        step(print);
    }
    return getCurrentState() == accept;
}

State* Turing::step(bool print) {
    if(print) {
        std::cout << std::endl << getCurrentState()->getName() << std::endl;
        printTape();
    }
    // Execute instruction
    char symbol = read();
    std::string action = parse(symbol);
    switch(action.at(0)) {
        case State::Action::RIGHT:
            move(true);
            break;
        case State::Action::LEFT:
            move(false);
            break;
        case State::Action::WRITE:
            write(action.at(1));
            break;
        case State::Action::NO_OP:
            break;
        default:
            throw std::runtime_error("Read unknown action");
            break;
    }
    return getCurrentState();
}

State* Turing::step() {
    return step(false);
}

void Turing::printTape() {
    // Extend tapes
    read();

    // Negative tape
    for(int i = negativeTape.size() - 1; i >= 0; i--) {
        char c;
        c = negativeTape.at(i);
        if(i == -head - 1) {
            std::cout << '[' <<  c << ']';
        } else {
            std::cout << c;
        }
    }
    // Positive tape
    for(int i = 0; i < tape.size(); i++) {
        char c;
        c = tape.at(i);
        if(i == head) {
            std::cout << '[' <<  c << ']';
        } else {
            std::cout << c;
        }
    }
    std::cout << std::endl;
}

void Turing::populateTape(std::string input) {
    for(int i = 0; i < input.size(); i++) {
        tape.at(i) = input.at(i);
    }
}