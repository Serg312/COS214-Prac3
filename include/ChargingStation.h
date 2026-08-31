#ifndef CHARGINGSTATION_H
#define CHARGINGSTATION_H

#include "EventUnit.h"

class ChargingStation : public EventUnit 
{
    private:
        int totalPorts;   ///< Total number of charging ports available.
        int activePorts;  ///< Number of ports currently supplying power.
    public:
        ChargingStation(const std::string& stationName, int portCount);
        void open() override;
        void close() override;
        void reportStatus() const override;
        virtual ~ChargingStation();
};

#endif
