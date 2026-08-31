#ifndef CHARGINGSTATION_H
#define CHARGINGSTATION_H

#include "EventUnit.h"

class ChargingStation : public EventUnit 
{
    private:
        int totalPorts;   
        int activePorts;
    public:
        ChargingStation(const std::string& stationName, int portCount);
        void open() override;
        void close() override;
        void reportStatus() const override;
        virtual ~ChargingStation();
};

#endif
