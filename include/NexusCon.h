#ifndef NEXUSCON_H
#define NEXUSCON_H

#include "EventGroup.h"
#include "Observer.h"
#include "Subject.h"

/**
 * @brief Allows use of the notice classes without including the entire Notice.h header, reducing compilation dependencies.
 */
class Notice;

/**
 * @brief Represents the NexusCon event, capable of receiving notices and reporting its status.
 *
 * The NexusCon class inherits from EventGroup, Observer, and Subject, allowing it to be part of the event's group structure,
 * receive notifications about various events or changes in the system, report its own status accordingly, and manage a list of observers.
 */
class NexusCon : public EventGroup, public Observer, public Subject
{
    public:
        /**
         * @brief Constructs a new NexusCon instance.
         * @param eventName The name of the NexusCon event, used for identification and reporting.
         */
        NexusCon(const std::string& eventName);
        /// @brief Updates the NexusCon event based on the received notice, preventing further participants from entering and closing all child components.
        /// @param notice The notice received by the NexusCon event.
        void update(const Notice& notice) override;
        /// @brief Destructor for the NexusCon class.
        virtual ~NexusCon();
};

#endif