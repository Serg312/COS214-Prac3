#ifndef COSPLAYMEETUPPOINT_H
#define COSPLAYMEETUPPOINT_H

#include "EventUnit.h"
#include "Observer.h"

/**
 * @brief Allows use of the notice classes without including the entire Notice.h header, reducing compilation dependencies.
 */
class Notice;

/**
 * @brief Represents a cosplay meetup point within the event, capable of receiving notices and reporting its status.
 *
 * The CosplayMeetupPoint class inherits from EventUnit and Observer, allowing it to be part of the event's unit structure,
 * receive notifications about various events or changes in the system, and report its own status accordingly.
 */
class CosplayMeetupPoint : public EventUnit, public Observer
{
    private:
        /// @brief The current number of participants at the cosplay meetup point.
        int participants;
    public:
        /**
         * @brief Constructs a new CosplayMeetupPoint instance.
         * @param pointName The name of the cosplay meetup point, used for identification and reporting.
         * @param participantCapacity The maximum number of participants allowed at this meetup point.
         */
        CosplayMeetupPoint(const std::string& pointName, int participantCapacity);
        /// @brief Opens the cosplay meetup point, allowing participants to enter.
        void open() override;
        /// @brief Closes the cosplay meetup point, preventing further participants from entering.
        void close() override;
        /// @brief Reports the current status of the cosplay meetup point, including participant count and capacity.
        void reportStatus() const override;
        /// @brief Updates the cosplay meetup point's state based on a received notice.
        void update(const Notice& notice) override;
        /// @brief Destructor for the CosplayMeetupPoint class.
        virtual ~CosplayMeetupPoint();
};

#endif