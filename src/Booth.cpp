#include "Booth.h"
#include "Notice.h"
#include <iostream>

Booth::Booth(const std::string& boothName, int visitorCapacity) : EventUnit(boothName, visitorCapacity), staffed(false), footTraffic(0) {}

void Booth::open() 
{
    isOpen = true;
    staffed = true;
    footTraffic = 0;
    std::cout << "[Booth] " << name << ": staff arrived, merchandise and banners available." << std::endl;
}

void Booth::close() 
{
    std::cout << "[Booth] " << name << ": merchandise packed away." << std::endl;
    staffed = false;
    footTraffic = 0;
    isOpen = false;
}

void Booth::reportStatus() const 
{
    std::cout << "Booth \"" << name << "\" - " << (staffed ? "STAFFED" : "UNSTAFFED") << ", foot traffic: " << footTraffic << ", capacity: " << capacity << std::endl;
}

void Booth::update(const Notice& notice)
{
    std::cout << "[Booth] " << name << " received notice: " << notice.getMessage() << std::endl;

    if (dynamic_cast<const EvacuationNotice*>(&notice) != nullptr)
    {
        std::cout << "[Booth] " << name << ": Evacuation, closing booth immediately." << std::endl;
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

Booth::~Booth() {}
