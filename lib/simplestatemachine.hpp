#ifndef SIMPLESTATEMACHINE_HPP
#define SIMPLESTATEMACHINE_HPP

#include <algorithm>
#include <functional>
#include <map>
#include <vector>

namespace ssm {

/*!
 *  \brief This class represents a statemachine
 */
template <class T>
class statemachine {
  static_assert(std::is_enum<T>::value, "Parameter must be an Enum");

 public:
  /*!
   * \brief Creates a new state machine
   */
  statemachine(std::vector<std::pair<T, T>> const transitions,
               T const initialState)
      : m_transitions{std::move(transitions)}, m_currentState(initialState) {}

  /*!
   * \brief Returns the current state
   */
  T getCurrentState() const { return m_currentState; }

  /*!
   * \brief Sets a method which will be called when a specific states is being
   * entered
   */
  void setEnterAction(T const state, std::function<void()> action) {
    m_enterActions.insert(std::make_pair(state, action));
  }

  /*!
   * \brief Sets a method which will be called when a specific states is being
   * exit
   */
  void setExitAction(T const state, std::function<void()> action) {
    m_exitActions.insert(std::make_pair(state, action));
  }

  /*!
   * \brief Performs the transition to the new state. Returns true if it was
   * succesfull
   */
  bool performTransitionTo(T const newState) {
    bool ret{false};

    if (std::find(m_transitions.begin(), m_transitions.end(),
                  std::make_pair(m_currentState, newState)) !=
        m_transitions.end()) {
      auto enterAction = m_enterActions.find(newState);
      if (enterAction != m_enterActions.end()) {
        enterAction->second();
      }

      auto exitAction = m_exitActions.find(m_currentState);
      if (exitAction != m_exitActions.end()) {
        exitAction->second();
      }

      m_currentState = newState;
      ret = true;
    }

    return ret;
  }

 private:
  std::vector<std::pair<T, T>> m_transitions;
  T m_currentState;

  std::map<T, std::function<void()>> m_enterActions;
  std::map<T, std::function<void()>> m_exitActions;
};

}  // namespace ssm

#endif