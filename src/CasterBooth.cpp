#include "CasterBooth.h"
#include "Notice.h"
#include <iostream>

CasterBooth::CasterBooth(const std::string& boothName, int crewCapacity) : EventUnit(boothName, crewCapacity), isLive(false), viewerCount(0) {}

void CasterBooth::open() 
{
    isOpen = true;
    isLive = true;
    viewerCount = 100; 
    std::cout << "[CasterBooth] " << name << ": going live, viewers joining the stream." << std::endl;
}

void CasterBooth::close() 
{
    isLive = false;
    viewerCount = 0;
    isOpen = false;
    std::cout << "[CasterBooth] " << name << ": broadcast ended." << std::endl;
}

void CasterBooth::reportStatus() const 
{
    std::cout << "CasterBooth \"" << name << "\" - " << (isLive ? "LIVE" : "OFFLINE") << ", viewers: " << viewerCount << ", capacity: " << capacity << std::endl;
}

void CasterBooth::update(const Notice& notice)
{
    std::cout << "[Booth] " << name << " received notice: " << notice.getMessage() << std::endl;

    if (dynamic_cast<const EvacuationNotice*>(&notice) != nullptr)
    {
        std::cout << "[Booth] " << name << ": Evacuation, closing caster booth immediately." << std::endl;
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
        std::cout << "[Booth] " << name << ": technical issue reported. Staff checking equipment." << std::endl;
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

CasterBooth::~CasterBooth() {}
