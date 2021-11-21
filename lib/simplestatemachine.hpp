#ifndef SIMPLESTATEMACHINE_HPP
#define SIMPLESTATEMACHINE_HPP

namespace ssm {

class statemachine {
    public:
        bool transitToState();
        void getState();
        void addEntryAction();
        void addExitAction();
        void deleteEntryAction();
        void deleteExitAction();
};

}

#endif