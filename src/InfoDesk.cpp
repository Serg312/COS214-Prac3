#include "InfoDesk.h"
#include "Notice.h"
#include <iostream>

InfoDesk::InfoDesk(const std::string& boothName, int visitorCapacity) : EventUnit(boothName, visitorCapacity), staffAvailable(false) {}

void InfoDesk::open() 
{
    isOpen = true;
    staffAvailable = true;
    std::cout << "[Info Desk] " << name << ": staff is available for help." << std::endl;
}

void InfoDesk::close() 
{
    std::cout << "[Info Desk] " << name << ": staff has left." << std::endl;
    staffAvailable = false;
    isOpen = false;
}

void InfoDesk::reportStatus() const 
{
    std::cout << "Info Desk \"" << name << "\" - " << (staffAvailable ? "STAFF AVAILABLE" : "NO STAFF AVAILABLE") << ", capacity: " << capacity << std::endl;
}

void InfoDesk::update(const Notice& notice)
{
    std::cout << "[Info Desk] " << name << " received notice: " << notice.getMessage() << std::endl;

    if (dynamic_cast<const EvacuationNotice*>(&notice) != nullptr)
    {
        std::cout << "[Info Desk] " << name << ": Evacuation, closing desk immediately." << std::endl;
        if (isOpen)
        {
            close();
        }
    }
    else if (dynamic_cast<const CapacityWarning*>(&notice) != nullptr)
    {
        std::cout << "[Info Desk] " << name << ": capacity warning received. Limiting new visitors." << std::endl;
    }
    else if (dynamic_cast<const TechnicalOutage*>(&notice) != nullptr)
    {
        std::cout << "[Info Desk] " << name << ": technical issue reported. Staff checking equipment." << std::endl;
    }
    else if (dynamic_cast<const ResumptionNotice*>(&notice) != nullptr)
    {
        std::cout << "[Info Desk] " << name << ": normal operations may resume." << std::endl;
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
        std::cout << "[Info Desk] " << name << ": notice acknowledged." << std::endl;
    }

}

InfoDesk::~InfoDesk() {}
