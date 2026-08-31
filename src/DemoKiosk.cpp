#include "DemoKiosk.h"
#include "Notice.h"
#include <iostream>

DemoKiosk::DemoKiosk(const std::string& kioskName, int hardwareUnits) : EventUnit(kioskName, hardwareUnits), totalUnits(hardwareUnits), poweredUnits(0) {}

void DemoKiosk::open() 
{
    std::cout << "[DemoKiosk] " << name << ": powering on hardware units." << std::endl;
    for (int i = 1; i <= totalUnits; ++i) 
    {
        std::cout << "  - unit " << i << " powered on" << std::endl;
    }
    poweredUnits = totalUnits;
    isOpen = true;
}

void DemoKiosk::close() 
{
    std::cout << "[DemoKiosk] " << name << ": shutting down hardware units..." << std::endl;
    for (int i = poweredUnits; i >= 1; --i) 
    {
        std::cout << "  - unit " << i << " powered off" << std::endl;
    }
    poweredUnits = 0;
    isOpen = false;
}

void DemoKiosk::reportStatus() const 
{
    std::cout << "DemoKiosk \"" << name << "\" - " << poweredUnits << "/" << totalUnits << " units powered on" << ", capacity: " << capacity << std::endl;
}

void DemoKiosk::update(const Notice& notice)
{
    std::cout << "[DemoKiosk] " << name << " received notice: " << notice.getMessage() << std::endl;

    if (dynamic_cast<const EvacuationNotice*>(&notice) != nullptr)
    {
        std::cout << "[DemoKiosk] " << name << ": Evacuation, closing kiosk immediately." << std::endl;
        if (isOpen)
        {
            close();
        }
    }
    else if (dynamic_cast<const CapacityWarning*>(&notice) != nullptr)
    {
        std::cout << "[DemoKiosk] " << name << ": Capacity warning received. Limiting new visitors." << std::endl;
    }
    else if (dynamic_cast<const TechnicalOutage*>(&notice) != nullptr)
    {
        std::cout << "[DemoKiosk] " << name << ": Dynamic Power Grid Throttling activated! Reducing power load to 50% capacity." << std::endl;
        poweredUnits = totalUnits/2;
    }
    else if (dynamic_cast<const ResumptionNotice*>(&notice) != nullptr)
    {
        std::cout << "[DemoKiosk] " << name << ": Normal operations may resume." << std::endl;
        if (isOpen) poweredUnits = totalUnits;
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
        std::cout << "[DemoKiosk] " << name << ": notice acknowledged." << std::endl;
    }

}

DemoKiosk::~DemoKiosk() {}
