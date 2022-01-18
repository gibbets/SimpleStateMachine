#include <gmock/gmock.h>

namespace ssm {

/*!
 *  \brief Callbacks called by the ssm unit tests. With gmock it is easier to verify that they are really called.
 */
class callbacksMock{
 public:
/*!
 *  \brief Mock method to be called for the exit action callback
 */
  MOCK_METHOD(void, exitAction, ());

   public:
/*!
 *  \brief Mock method to be called for the enter action callback
 */
  MOCK_METHOD(void, enterAction, ());
};

}