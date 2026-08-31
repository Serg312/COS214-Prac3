#ifndef CHARGINGSTATION_H
#define CHARGINGSTATION_H

#include "EventUnit.h"
#include "Observer.h"

/**
 * @brief Represents a charging station within the event, capable of receiving notices and reporting its status.
 *
 * The ChargingStation class inherits from EventUnit and Observer, allowing it to be part of the event's unit structure
 * and to receive notifications about various events or changes in the system.
 */
class ChargingStation : public EventUnit, public Observer
{
    private:
        /// @brief The total number of charging ports available at the station. This is used to manage capacity and availability.
        int totalPorts;   
        /// @brief The number of charging ports currently in use. This is used to monitor utilization and manage resources.
        int activePorts;
    public:
        /// @brief Constructs a new ChargingStation instance.
        /// @param stationName The name of the charging station, used for identification and reporting.
        /// @param portCount The total number of charging ports available at the station. This is used to manage capacity and availability.
        ChargingStation(const std::string& stationName, int portCount);
        /// @brief Opens the charging station for operation. This method sets the station's status to open and may trigger any necessary notifications or state changes.
        void open() override;
        /// @brief Closes the charging station, preventing further charging access. This method sets the station's status to closed and may trigger any necessary notifications or state changes.
        void close() override;
        /// @brief Reports the current status of the charging station, including its total and active port counts.
        void reportStatus() const override;
        /// @brief Updates the charging station's state based on a received notice.
        void update(const Notice& notice) override;
        /// @brief Destructor for the ChargingStation class.
        virtual ~ChargingStation();
};

#endif
