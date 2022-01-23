# SimpleStateMachine

SimpleStateMachine is a header-only C++ library to implement statemachines.

## Installation

Clone the repo and copy the header file where ever you need it.

```bash
git clone https://github.com/gibbets/SimpleStateMachine.git
```

## Usage

```c
#include "simpelstatemachine.hpp"

/*
1. Define your States
2. Create a list of allowed transitions
3. Create your state machine
4. Define actions when entering or leaving a state
*/

enum states { start, running, end };

/*
This defines two allowed transitions: from start to running, and from running to end;
*/
std::pair<states, states> firstTransition(states::start, states::running);
std::pair<states, states> anotherTransition(states::running, states::end);
std::vector<std::pair<states, states> myTransistions;
myTransistions.push_back(firstTransition);
myTransistions.push_back(anotherTransistion);

ssm::statemachine<states> myStatemachine(myTransistion, states::start);

//Set an action whenever we are entering the running state
myStatemachine.setEnterAction(states::running, 
    [] () { std::cout << "Enter running state";});

//Set an action whenever we are leaving the running state
myStatemachine.setExitAction(states::running, 
    [] () { std::cout << "Leaving running state";});

//Set an action when we we are moving from running to end
myStatemachine.setTransitionAction(std::make_pair(states::running, states::end), 
    []() { std::cout << "Going from running to end"; });

//Perform a transition to running
myStatemachine.performTransitionTo(states::running);

//New state is running
myStatemachine.getCurrentState();

//Perform a transition to start
myStatemachine.performTransitionTo(states::start);

//State is still running, because from running to start is not allowed
myStatemachine.getCurrentState();
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.