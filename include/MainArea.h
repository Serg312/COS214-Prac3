#ifndef MAINAREA_H
#define MAINAREA_H

#include "EventGroup.h"
#include "Observer.h"
#include "Subject.h"

/**
 * @brief Allows use of the notice classes without including the entire Notice.h header, reducing compilation dependencies.
 */
class Notice;

/**
 * @brief Represents the main area within the event, capable of receiving notices and reporting its status.
 *
 * The MainArea class inherits from EventGroup, Observer, and Subject, allowing it to be part of the event's group structure,
 * receive notifications about various events or changes in the system, report its own status accordingly, and manage a list of observers.
 */
class MainArea : public EventGroup, public Observer, public Subject
{
    public:
        /**
         * @brief Constructs a new MainArea instance.
         * @param areaName The name of the main area, used for identification and reporting.
         */
        MainArea(const std::string& areaName);
        /// @brief Updates the main area based on the received notice, preventing further participants from entering and closing all child components.
        /// @param notice The notice received by the main area.
        void update(const Notice& notice) override;
        /// @brief Destructor for the MainArea class.
        virtual ~MainArea();
};

#endif