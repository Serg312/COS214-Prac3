#include "ChargingStation.h"
#include "Notice.h"
#include <iostream>

ChargingStation::ChargingStation(const std::string& stationName, int portCount) : EventUnit(stationName, portCount), totalPorts(portCount), activePorts(0) {}

void ChargingStation::open() 
{
    activePorts = totalPorts;
    isOpen = true;
    std::cout << "[ChargingStation] " << name << ": all " << totalPorts << " ports supplying power." << std::endl;
}

void ChargingStation::close() 
{
    std::cout << "[ChargingStation] " << name << ": powering down ports." << std::endl;
    activePorts = 0;
    isOpen = false;
}

void ChargingStation::reportStatus() const 
{
    std::cout << "ChargingStation \"" << name << "\" - " << activePorts << "/" << totalPorts << " ports active" << ", capacity: " << capacity << std::endl;
}

void ChargingStation::update(const Notice& notice)
{
    std::cout << "[Booth] " << name << " received notice: " << notice.getMessage() << std::endl;

    if (dynamic_cast<const EvacuationNotice*>(&notice) != nullptr)
    {
        std::cout << "[Booth] " << name << ": Evacuation, station closing immediately." << std::endl;
        if (isOpen)
        {
            close();
        }
    }
    else if (dynamic_cast<const CapacityWarning*>(&notice) != nullptr)
    {
        std::cout << "[Booth] " << name << ": capacity warning received. Limiting new visitors." << std::endl;
    }
    else if (dynamic_cast<const TechnicalOutage*>(&notice) != nullptr)
    {
        std::cout << "[Booth] " << name << ": technical issue reported. Staff checking charging ports." << std::endl;
        activePorts = 0;
    }
    else if (dynamic_cast<const ResumptionNotice*>(&notice) != nullptr)
    {
        std::cout << "[Booth] " << name << ": normal operations may resume." << std::endl;
    }
    else if (dynamic_cast<const OpenNotice*>(&notice) != nullptr)
    {
        if (!isOpen)
        {
            open();
        }
    }
    else
    {
        std::cout << "[Booth] " << name << ": notice acknowledged." << std::endl;
    }

}

ChargingStation::~ChargingStation() {}
