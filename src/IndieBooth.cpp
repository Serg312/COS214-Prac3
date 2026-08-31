#include "IndieBooth.h"
#include "Notice.h"
#include <iostream>

IndieBooth::IndieBooth(const std::string& boothName, int visitorCapacity) : EventUnit(boothName, visitorCapacity), developerPresent(false) {}

void IndieBooth::open() 
{
    developerPresent = true;
    isOpen = true;
    std::cout << "[Indie Booth] " << name << ": developer arrived, booth open." << std::endl;
}

void IndieBooth::close() 
{
    std::cout << "[Indie Booth] " << name << ": booth closed." << std::endl;
    developerPresent = false;
    isOpen = false;
}

void IndieBooth::reportStatus() const 
{
    std::cout << "Indie Booth \"" << name << "\" - " << (developerPresent ? "DEVELOPER PRESENT" : "NO DEVELOPER PRESENT")  << ", capacity: " << capacity << std::endl;
}

void IndieBooth::update(const Notice& notice)
{
    std::cout << "[Indie Booth] " << name << " received notice: " << notice.getMessage() << std::endl;

    if (dynamic_cast<const EvacuationNotice*>(&notice) != nullptr)
    {
        std::cout << "[Indie Booth] " << name << ": Evacuation, closing booth immediately." << std::endl;
        if (isOpen)
        {
            close();
        }
    }
    else if (dynamic_cast<const CapacityWarning*>(&notice) != nullptr)
    {
        std::cout << "[Indie Booth] " << name << ": capacity warning received. Limiting new visitors." << std::endl;
    }
    else if (dynamic_cast<const TechnicalOutage*>(&notice) != nullptr)
    {
        std::cout << "[Indie Booth] " << name << ": technical issue reported. Staff checking equipment." << std::endl;
    }
    else if (dynamic_cast<const ResumptionNotice*>(&notice) != nullptr)
    {
        std::cout << "[Indie Booth] " << name << ": normal operations may resume." << std::endl;
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
        std::cout << "[Indie Booth] " << name << ": notice acknowledged." << std::endl;
    }

}

IndieBooth::~IndieBooth() {}
