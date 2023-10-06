#include "Turing.hpp"

Turing::Turing(String input) :
    head(0),
    tape(std::vector<char>(input.size(), '\0')){
    for(const char c : input) {
        tape.push_back(c);
    }
}

Turing::Turing() {
    *this = Turing("");
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
    // First instruction is always read?
    return true;
}

State* Turing::step() {
    // Execute instruction
    // switch(instruction) {
    //     case "r":

    // }
}
