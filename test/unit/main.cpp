#include <gtest/gtest.h>

#include <vector>

#include "callbacksMock.hpp"
#include "simplestatemachine.hpp"

enum states { start, running, end };

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

  ssm::callbacksMock callbacks;

  myStatemachine.setEnterAction(states::running, [&callbacks] () { callbacks.enterAction();});

  myStatemachine.setExitAction(
      states::start, [&callbacks]() { callbacks.exitAction(); });

  myStatemachine.setTransitionAction(transition, [&callbacks]() { callbacks.transitionAction(); });

  ASSERT_EQ(myStatemachine.getCurrentState(), states::start);

  EXPECT_CALL(callbacks, exitAction);
  EXPECT_CALL(callbacks, enterAction);
  EXPECT_CALL(callbacks, transitionAction);
  ASSERT_TRUE(myStatemachine.performTransitionTo(states::running));
  ASSERT_EQ(myStatemachine.getCurrentState(), states::running);

  ASSERT_FALSE(myStatemachine.performTransitionTo(states::start));
  ASSERT_EQ(myStatemachine.getCurrentState(), states::running);
}