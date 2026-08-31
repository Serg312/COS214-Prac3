#ifndef PRACTICEZONE_H
#define PRACTICEZONE_H

#include "EventGroup.h"
#include "Observer.h"
#include "Subject.h"

/**
 * @brief Allows use of the notice classes without including the entire Notice.h header, reducing compilation dependencies.
 */
class Notice;

/**
 * @brief Represents a practice zone within the event, capable of receiving notices and reporting its status.
 *
 * The PracticeZone class inherits from EventGroup, Observer, and Subject, allowing it to be part of the event's group structure,
 * receive notifications about various events or changes in the system, report its own status accordingly, and manage a list of observers.
 */
class PracticeZone : public EventGroup, public Observer, public Subject
{
    public:
        /// @brief Constructs a new PracticeZone instance.
        /// @param zoneName The name of the practice zone, used for identification and reporting.
        PracticeZone(const std::string& zoneName);
        /// @brief Updates the practice zone based on the received notice.
        /// @param notice The notice received by the practice zone.
        void update(const Notice& notice) override;
        /// @brief Destructor for the PracticeZone class.
        virtual ~PracticeZone();
};

#endif