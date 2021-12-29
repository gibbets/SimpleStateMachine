#ifndef SIMPLESTATEMACHINE_HPP
#define SIMPLESTATEMACHINE_HPP

#include <vector>
#include <map>
#include <functional>

namespace ssm {

/*! 
 *  \brief This class represents a statemachine
 */
template <class T>
class statemachine {
    public:
        /*!
        * \brief Creates a new state machine
        */
        statemachine(std::vector<std::pair<T, T>> transitions) : 
        m_transitions{transitions}
        {

        }

        /*!
        * \brief Sets a method which will be called when a specific states is being entered
        */
        void setEnterAction(T state, std::function<void()> action) {
            m_enterActions.insert(std::make_pair(state, action));
        }

    private:
        std::vector<std::pair<T, T>> m_transitions;
        std::map<T, std::function<void()>> m_enterActions;
};

}

#endif