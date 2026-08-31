#ifndef CHARGINGSTATION_H
#define CHARGINGSTATION_H

#include "EventUnit.h"
#include "Observer.h"

class ChargingStation : public EventUnit, public Observer
{
    private:
        int totalPorts;   
        int activePorts;
    public:
        ChargingStation(const std::string& stationName, int portCount);
        void open() override;
        void close() override;
        void reportStatus() const override;
        void update(const Notice& notice) override;
        virtual ~ChargingStation();
};

#endif
