#ifndef EVENTCONTROL_H
#define EVENTCONTROL_H

#include "Subject.h"

/**
 * @brief Allows use of the notice classes without including the entire Notice.h header, reducing compilation dependencies.
 */
class Notice;
/**
 * @brief Manages the issuance of notices to registered observers within the event system.
 *
 * The EventControl class inherits from Subject, allowing it to maintain a list of observers and notify them of various
 * notices or events. It serves as the central point for issuing notices to all registered observers in the system.
 */
class EventControl : public Subject
{
    public:
        /// @brief Constructs a new EventControl instance, initializing the subject-observer relationship.
        EventControl();
        /// @brief Issues a notice to all registered observers.
        void issueNotice(const Notice& notice);
        /// @brief Destructor for the EventControl class.
        virtual ~EventControl();
};

#endif