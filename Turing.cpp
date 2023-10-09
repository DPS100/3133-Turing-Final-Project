#include "Turing.hpp"

Turing::Turing(std::string input) :
    head(0),
    tape(std::vector<char>(input.size(), '\0')){
    for(const char c : input) {
        tape.push_back(c);
    }
}

Turing::Turing() {
    *this = Turing("");
}

Turing::Turing(std::vector<State*> states, std::string input) :
    DFA(states) {
    *this = Turing(input);
}

Turing::Turing(std::vector<State*> states, State* accept, State* decline) :
    DFA(states, accept, decline) {
    *this = Turing();
}

Turing::Turing(std::vector<State*> states, State* accept, State* decline, std::string input) :
    DFA(states, accept, decline) {
    *this = Turing(input);
}

char Turing::read() {
    if(head >= 0) {
        return tape.at(head);
    } else {
        return negativeTape.at(-head);
    }
}

void Turing::write(char symbol) {
    if(head >= 0) {
        tape.reserve(head);
        tape.at(head) = symbol;
    } else {
        negativeTape.reserve(-head);  
        negativeTape.at(-head) = symbol;
    }
}

void Turing::move(bool positive) {
    positive ? head++ : head--;
}

bool Turing::run() {
    while(this->getCurrentState() != this->accept && this->getCurrentState() != this->decline) {
        step();
    }
    return true;
}

State* Turing::step() {
    // Execute instruction
    std::string action = this->parse(read());
    switch(action.at(0)) {
        case State::Action::RIGHT:
            head++;
            break;
        case State::Action::LEFT:
            head--;
            break;
        case State::Action::WRITE:
            tape.at(head) = action.at(1);
        default:
        case State::Action::NO_OP:
            break;
    }
    return this->getCurrentState();
}

std::string Turing::getTape() {
    std::string tapeString = "";
    for(const char c : Turing::negativeTape) {
        std::string tempString = std::string(1, c);
        tempString.append(tapeString);
        tapeString = tempString;
    }
    for(const char c : Turing::tape) {
        tapeString.append(std::string(1,c));
    }
    return tapeString;
}