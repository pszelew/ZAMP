#ifndef ACCESSCONTROLL_HH
#define ACCESSCONTROLL_HH

#include <mutex>

/*!
 * \file
 * \brief Contains the definition of a class AccessControl
 */


/*!
 * \brief Containst info about changes
 *
 */
class AccessControl {
   /*!
    * \brief Mutex to lock access to the object
    */
    std::mutex   _InternalGuard;
   /*!
    * \brief A flag to signalize changes
    *
    * \retval true - there was a change in the scene
    * \retval false - otherwise
    */ 
    bool         _Changed = false;
   /*!
    * \brief Mutex to lock all the scene
    */
    std::mutex  _ExternalGuard;
 public:
  /*!
   * \brief Check if there was a change in the scene
   *
   * Dostęp do informacji o zmianie.
   * \retval true - there was a change in the scene
   * \retval false - otherwise
   */
   bool IsChanged() const { return _Changed; }
  /*!
   * \brief Mark change in the scene
   */
   void MarkChange() { _InternalGuard.lock();  _Changed = true;  _InternalGuard.unlock(); }
  /*!
   * \brief Mark removing change in the scene
   */
   void CancelChange() { _InternalGuard.lock();  _Changed = false;  _InternalGuard.unlock(); }
  /*!
   * \brief Lock access to the scene
   */
   void LockAccess() { _ExternalGuard.lock(); }
  /*!
   * \brief Unlock access to the scene
   */
   void UnlockAccess() { _ExternalGuard.unlock(); } 
};




#endif 
