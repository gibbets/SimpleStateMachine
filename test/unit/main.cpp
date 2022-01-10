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

TEST(ssm_test, perform_tranisition) {
    std::pair<states, states> transition(states::start, states::running);

    std::vector<std::pair<states, states>> myTransitions; 
    myTransitions.push_back(transition);

    ssm::statemachine<states> myStatemachine(myTransitions, states::start);

    int callCounterEnterActions{0};
    myStatemachine.setEnterAction(states::running, [&callCounterEnterActions]() {
        callCounterEnterActions++;
    });

    int callCounterExitActions{0};
    myStatemachine.setExitAction(states::start, [&callCounterExitActions]() {
        callCounterExitActions++;
    });

    ASSERT_EQ(myStatemachine.getCurrentState(), states::start);

    ASSERT_TRUE(myStatemachine.performTransitionTo(states::running));
    ASSERT_EQ(myStatemachine.getCurrentState(), states::running);
    ASSERT_EQ(callCounterEnterActions, 1);
    ASSERT_EQ(callCounterExitActions, 1);

    ASSERT_FALSE(myStatemachine.performTransitionTo(states::start));
    ASSERT_EQ(myStatemachine.getCurrentState(), states::running);
    ASSERT_EQ(callCounterEnterActions, 1);
    ASSERT_EQ(callCounterExitActions, 1);
}