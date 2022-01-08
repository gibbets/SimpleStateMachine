#include "simplestatemachine.hpp"

enum states {
    start,
    running,
    end
};

int main() {
    std::pair<states, states> transition(states::start, states::running);

    std::vector<std::pair<states, states>> myTransitions; 
    myTransitions.push_back(transition);

    ssm::statemachine<states> myStatemachine(myTransitions, states::start);

    return 0;
}