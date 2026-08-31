#ifndef FIRSTAIDPOINT_H
#define FIRSTAIDPOINT_H

#include "EventUnit.h"
#include "Observer.h"

/**
 * @brief Allows use of the notice classes without including the entire Notice.h header, reducing compilation dependencies.
 */
class Notice;

/**
 * @brief Represents a first aid point within the event, capable of receiving notices and reporting its status.
 *
 * The FirstAidPoint class inherits from EventUnit and Observer, allowing it to be part of the event's unit structure,
 * receive notifications about various events or changes in the system, and report its own status accordingly.
 */
class FirstAidPoint : public EventUnit, public Observer
{
    private:
        /// @brief Indicates whether the first aid point is ready for emergency situations.
        bool emergencyReady;
    public:
        /**
         * @brief Constructs a new FirstAidPoint instance.
         * @param pointName The name of the first aid point, used for identification and reporting.
         * @param patientCapacity The maximum number of patients that can be treated at this first aid point.
         */
        FirstAidPoint(const std::string& pointName, int patientCapacity);
        /// @brief Opens the first aid point, making it available for use.
        void open() override;
        /// @brief Closes the first aid point, preventing further use.
        void close() override;
        /// @brief Reports the current status of the first aid point.
        void reportStatus() const override;
        /// @brief Updates the first aid point based on the received notice.
        /// @param notice The notice received by the first aid point.
        void update(const Notice& notice) override;
        /// @brief Destructor for the FirstAidPoint class.
        virtual ~FirstAidPoint();
};

#endif