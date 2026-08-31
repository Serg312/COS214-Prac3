#include "PracticeBooth.h"
#include "Notice.h"
#include <iostream>

PracticeBooth::PracticeBooth(const std::string& boothName, int visitorCapacity) : EventUnit(boothName, visitorCapacity), occupied(false) {}

void PracticeBooth::open() 
{
    occupied = false;
    isOpen = true;
    std::cout << "[Practice Booth] " << name << ": practice available to all." << std::endl;
}

void PracticeBooth::close() 
{
    std::cout << "[Practice Booth] " << name << ": practice no longer available." << std::endl;
    occupied = false;
    isOpen = false;
}

void PracticeBooth::reportStatus() const 
{
    std::cout << "Practice Booth \"" << name << "\" - " << (occupied ? "OCCUPIED" : "VACANT")  << ", capacity: " << capacity << std::endl;
}

void PracticeBooth::update(const Notice& notice)
{
    std::cout << "[Practice Booth] " << name << " received notice: " << notice.getMessage() << std::endl;

    if (dynamic_cast<const EvacuationNotice*>(&notice) != nullptr)
    {
        std::cout << "[Practice Booth] " << name << ": Evacuation, closing practice booth immediately." << std::endl;
        if (isOpen)
        {
            close();
        }
    }
    else if (dynamic_cast<const CapacityWarning*>(&notice) != nullptr)
    {
        std::cout << "[Practice Booth] " << name << ": capacity warning received. Limiting new visitors." << std::endl;
    }
    else if (dynamic_cast<const TechnicalOutage*>(&notice) != nullptr)
    {
        std::cout << "[Practice Booth] " << name << ": technical issue reported. Staff checking equipment." << std::endl;
    }
    else if (dynamic_cast<const ResumptionNotice*>(&notice) != nullptr)
    {
        std::cout << "[Practice Booth] " << name << ": normal operations may resume." << std::endl;
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
        std::cout << "[Practice Booth] " << name << ": notice acknowledged." << std::endl;
    }

}

PracticeBooth::~PracticeBooth() {}
