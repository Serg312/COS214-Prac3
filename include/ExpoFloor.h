#ifndef EXPOFLOOR_H
#define EXPOFLOOR_H

#include "EventGroup.h"
#include "Observer.h"
#include "Subject.h"

/**
 * @brief Allows use of the notice classes without including the entire Notice.h header, reducing compilation dependencies.
 */
class Notice;

/**
 * @brief Represents an expo floor within the event, capable of receiving notices, reporting its status, and managing child components.
 *
 * The ExpoFloor class inherits from EventGroup, Observer, and Subject, allowing it to be part of the event's group structure,
 * receive notifications about various events or changes in the system, report its own status accordingly, and manage a list of observers.
 */
class ExpoFloor : public EventGroup, public Observer, public Subject
{
    public:
        /**
         * @brief Constructs a new ExpoFloor instance.
         * @param floorName The name of the expo floor, used for identification and reporting.
         */
        ExpoFloor(const std::string& floorName);
        /// @brief Updates the expo floor based on the received notice, preventing further participants from entering and closing all child components.
        /// @param notice The notice received by the expo floor.
        void update(const Notice& notice) override;
        /// @brief Destructor for the ExpoFloor class.
        virtual ~ExpoFloor();
};

#endif