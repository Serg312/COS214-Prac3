#ifndef DEMOKIOSK_H
#define DEMOKIOSK_H

#include "EventUnit.h"
#include "Observer.h"

/**
 * @brief Represents a demo kiosk within the event, capable of receiving notices and reporting its status.
 *
 * The DemoKiosk class inherits from EventUnit and Observer, allowing it to be part of the event's unit structure,
 * receive notifications about various events or changes in the system, and report its own status accordingly.
 */
class DemoKiosk : public EventUnit, public Observer
{
    private:
        /// @brief The total number of hardware units in the demo kiosk.
        int totalUnits;
        /// @brief The number of currently powered-on hardware units in the demo kiosk.
        int poweredUnits;
    public:
        /**
         * @brief Constructs a new DemoKiosk instance.
         * @param kioskName The name of the demo kiosk, used for identification and reporting.
         * @param hardwareUnits The total number of hardware units in this demo kiosk.
         */
        DemoKiosk(const std::string& kioskName, int hardwareUnits);
        /// @brief Opens the demo kiosk, powering on all hardware units.
        void open() override;
        /// @brief Closes the demo kiosk, powering off all hardware units.
        void close() override;
        /// @brief Reports the current status of the demo kiosk, including hardware unit counts.
        void reportStatus() const override;
        /// @brief Updates the demo kiosk's state based on a received notice.
        void update(const Notice& notice) override;
        /// @brief Destructor for the DemoKiosk class.
        virtual ~DemoKiosk();
};

#endif
