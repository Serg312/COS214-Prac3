#ifndef CASTERBOOTH_H
#define CASTERBOOTH_H

#include "EventUnit.h"
#include "Observer.h"

/**
 * @brief Represents a caster booth within the event, capable of receiving notices and reporting its status.
 *
 * The CasterBooth class inherits from EventUnit and Observer, allowing it to be part of the event's unit structure
 * and to receive notifications about various events or changes in the system.
 */
class CasterBooth : public EventUnit, public Observer
{
    private:
        /// @brief Indicates whether the caster booth is currently live. True if live, false otherwise.
        bool isLive;       
        /// @brief Tracks the number of viewers currently watching the caster booth. This is used to monitor engagement and manage resources.
        int viewerCount;   
    public:
        /// @brief Constructs a new CasterBooth instance.
        /// @param boothName The name of the caster booth, used for identification and reporting.
        /// @param crewCapacity The maximum number of crew members that can be assigned to the caster booth at any given time. This is used to manage staffing levels.
        CasterBooth(const std::string& boothName, int crewCapacity);
        /// @brief Opens the caster booth for live streaming. This method sets the booth's status to live and may trigger any necessary notifications or state changes.
        void open() override;
        /// @brief Closes the caster booth, ending the live stream. This method sets the booth's status to not live and may trigger any necessary notifications or state changes.
        void close() override;
        /// @brief Reports the current status of the caster booth, including its live status and viewer count.
        void reportStatus() const override;
        /// @brief Updates the caster booth's state based on a received notice.
        /// @param notice The notice containing information about the event or change.
        void update(const Notice& notice) override;
        /// @brief Destructor for the CasterBooth class.
        virtual ~CasterBooth();
};

#endif
