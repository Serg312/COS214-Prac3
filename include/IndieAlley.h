#ifndef INDIEALLEY_H
#define INDIEALLEY_H

#include "EventGroup.h"
#include "Observer.h"
#include "Subject.h"

/**
 * @brief Allows use of the notice classes without including the entire Notice.h header, reducing compilation dependencies.
 */
class Notice;

/**
 * @brief Represents an indie alley within the event, capable of receiving notices, reporting its status, and managing child components.
 *
 * The IndieAlley class inherits from EventGroup, Observer, and Subject, allowing it to be part of the event's group structure,
 * receive notifications about various events or changes in the system, report its own status accordingly, and manage a list of observers.
 */
class IndieAlley : public EventGroup, public Observer, public Subject
{
    public:
        /**
         * @brief Constructs a new IndieAlley instance.
         * @param alleyName The name of the indie alley, used for identification and reporting.
         */
        IndieAlley(const std::string& alleyName);
        /// @brief Updates the indie alley based on the received notice, preventing further participants from entering and closing all child components.
        void update(const Notice& notice) override;
        /// @brief Destructor for the IndieAlley class.
        virtual ~IndieAlley();
};

#endif