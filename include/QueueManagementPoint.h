#ifndef QUEUEMANAGEMENTPOINT_H
#define QUEUEMANAGEMENTPOINT_H

#include "EventUnit.h"
#include "Observer.h"

/**
 * @brief Represents a queue management point within the event, capable of receiving notices and reporting its status.
 *
 * The QueueManagementPoint class inherits from EventUnit and Observer, allowing it to be part of the event's unit structure,
 * receive notifications about various events or changes in the system, and report its own status accordingly.
 */
class QueueManagementPoint : public EventUnit, public Observer
{
    private:
        /// @brief The current length of the queue at the management point.
        int queueLength;
    public:
        /// @brief Constructs a new QueueManagementPoint instance.
        /// @param pointName The name of the queue management point, used for identification and reporting.
        /// @param maxQueueLength The maximum length of the queue at the management point.
        QueueManagementPoint(const std::string& pointName, int maxQueueLength);
        /// @brief Opens the queue management point, allowing participants to enter the queue.
        void open() override;
        /// @brief Closes the queue management point, preventing further participants from entering the queue.
        void close() override;
        /// @brief Reports the current status of the queue management point.
        void reportStatus() const override;
        /// @brief Updates the queue management point based on the received notice.
        /// @param notice The notice received by the queue management point.
        void update(const Notice& notice) override;
        /// @brief Destructor for the QueueManagementPoint class.
        virtual ~QueueManagementPoint();
};

#endif
