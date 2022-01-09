#include <gtest/gtest.h>
#include <vector>

#include "simplestatemachine.hpp"

enum states {
    start,
    running,
    end
};

TEST(ssm_test, object_exists) {
    std::pair<states, states> transition(states::start, states::running);

    std::vector<std::pair<states, states>> myTransitions; 
    myTransitions.push_back(transition);

    ssm::statemachine<states> myStatemachine(myTransitions, states::start);

    ASSERT_EQ(myStatemachine.getCurrentState(), states::start);
}