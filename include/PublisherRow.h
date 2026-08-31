#ifndef PUBLISHERROW_H
#define PUBLISHERROW_H

#include "EventGroup.h"
#include "Observer.h"
#include "Subject.h"

/**
 * @brief Allows use of the notice classes without including the entire Notice.h header, reducing compilation dependencies.
 */
class Notice;

/**
 * @brief Represents a publisher row within the event, capable of receiving notices and reporting its status.
 *
 * The PublisherRow class inherits from EventGroup, Observer, and Subject, allowing it to be part of the event's group structure,
 * receive notifications about various events or changes in the system, report its own status accordingly, and manage a list of observers.
 */
class PublisherRow : public EventGroup, public Observer, public Subject
{
    public:
        /// @brief Constructs a new PublisherRow instance.
        /// @param rowName The name of the publisher row, used for identification and reporting.
        PublisherRow(const std::string& rowName);
        /// @brief Updates the publisher row based on the received notice.
        /// @param notice The notice received by the publisher row.
        void update(const Notice& notice) override;
        /// @brief Destructor for the PublisherRow class.
        virtual ~PublisherRow();
};

#endif