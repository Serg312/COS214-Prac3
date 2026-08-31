#include "DemoKiosk.h"
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

DemoKiosk::~DemoKiosk() {}
