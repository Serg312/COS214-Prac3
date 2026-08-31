#include "FirstAidPoint.h"
#include "Notice.h"
#include <iostream>

FirstAidPoint::FirstAidPoint(const std::string& boothName, int visitorCapacity) : EventUnit(boothName, visitorCapacity), emergencyReady(true) {}

void FirstAidPoint::open() 
{
    isOpen = true;
    emergencyReady = true;
    std::cout << "[FirstAid Point] " << name << ": staff present and ready for a medical emergency." << std::endl;
}

void FirstAidPoint::close() 
{
    std::cout << "[FirstAid Point] " << name << ": not ready for medical assistance." << std::endl;
    emergencyReady = false;
    isOpen = false;
}

void FirstAidPoint::reportStatus() const 
{
    std::cout << "FirstAid Point \"" << name << "\" - " << (emergencyReady ? "MEDICAL ASSISTANCE AVAILABLE" : "MEDICAL ASSISTANCE UNAVAILABLE") << ", capacity: " << capacity << std::endl;
}

void FirstAidPoint::update(const Notice& notice)
{
    std::cout << "[FirstAid Point] " << name << " received notice: " << notice.getMessage() << std::endl;

    if (dynamic_cast<const EvacuationNotice*>(&notice) != nullptr)
    {
        std::cout << "[FirstAid Point] " << name << ": Evacuation, closing FirstAid point immediately." << std::endl;
        if (isOpen)
        {
            close();
        }
    }
    else if (dynamic_cast<const CapacityWarning*>(&notice) != nullptr)
    {
        std::cout << "[FirstAid Point] " << name << ": capacity warning received. Limiting new visitors." << std::endl;
    }
    else if (dynamic_cast<const TechnicalOutage*>(&notice) != nullptr)
    {
        std::cout << "[FirstAid Point] " << name << ": technical issue reported. Staff checking equipment." << std::endl;
    }
    else if (dynamic_cast<const ResumptionNotice*>(&notice) != nullptr)
    {
        std::cout << "[FirstAid Point] " << name << ": normal operations may resume." << std::endl;
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
        std::cout << "[FirstAid Point] " << name << ": notice acknowledged." << std::endl;
    }

}

FirstAidPoint::~FirstAidPoint() {}
