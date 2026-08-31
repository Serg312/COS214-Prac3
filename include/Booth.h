#ifndef BOOTH_H
#define BOOTH_H

#include "EventUnit.h"
#include "Observer.h"

/**
 * @brief Represents a booth within the event, capable of receiving notices and reporting its status.
 *
 * The Booth class inherits from EventUnit and Observer, allowing it to be part of the event's unit structure
 * and to receive notifications about various events or changes in the system.
 */
class Booth : public EventUnit, public Observer
{
    private:
        /// @brief Indicates whether the booth is currently staffed. True if staffed, false otherwise.
        bool staffed;
        /// @brief Tracks the number of visitors currently at the booth. This is used to monitor foot traffic and manage capacity.
        int footTraffic;   
    public:
        /// @brief Constructs a new Booth instance.
        /// @param boothName The name of the booth, used for identification and reporting.
        /// @param visitorCapacity The maximum number of visitors that the booth can accommodate at any given time. This is used to enforce capacity limits.
        Booth(const std::string& boothName, int visitorCapacity);
        /// @brief Opens the booth for operation. This method sets the booth's status to open and may trigger any necessary notifications or state changes.
        void open() override;
        /// @brief Closes the booth, preventing further visitor access. This method sets the booth's status to closed and may trigger any necessary notifications or state changes.
        void close() override;
        /// @brief Reports the current status of the booth, including its staffing status and visitor count.
        void reportStatus() const override;
        /// @brief Updates the booth's state based on a received notice.
        /// @param notice The notice containing information about the event or change.
        void update(const Notice& notice) override;
        /// @brief Destructor for the Booth class.
        virtual ~Booth();
};

#endif
