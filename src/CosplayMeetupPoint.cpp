#include "CosplayMeetupPoint.h"
#include "Notice.h"
#include <iostream>

CosplayMeetupPoint::CosplayMeetupPoint(const std::string& boothName, int visitorCapacity) : EventUnit(boothName, visitorCapacity), participants(0) {}

void CosplayMeetupPoint::open() 
{
    participants = 0;
    isOpen = true;
    std::cout << "[Cosplay Meetup Point] " << name << ": meetup point open, come join!" << std::endl;
}

void CosplayMeetupPoint::close() 
{
    std::cout << "[Cosplay Meetup Point] " << name << ": meetup point closed." << std::endl;
    participants = 0;
    isOpen = false;
}

void CosplayMeetupPoint::reportStatus() const 
{
    std::cout << "Cosplay Meetup Point \"" << name << "\" - " << "participants: " << participants << ", capacity: " << capacity << std::endl;
}

void CosplayMeetupPoint::update(const Notice& notice)
{
    std::cout << "[Cosplay Meetup Point] " << name << " received notice: " << notice.getMessage() << std::endl;

    if (dynamic_cast<const EvacuationNotice*>(&notice) != nullptr)
    {
        std::cout << "[Cosplay Meetup Point] " << name << ": Evacuation, please leave meetup point immediately." << std::endl;
        if (isOpen)
        {
            close();
        }
    }
    else if (dynamic_cast<const CapacityWarning*>(&notice) != nullptr)
    {
        std::cout << "[Cosplay Meetup Point] " << name << ": capacity warning received. Limiting new visitors." << std::endl;
    }
    else if (dynamic_cast<const TechnicalOutage*>(&notice) != nullptr)
    {
        std::cout << "[Cosplay Meetup Point] " << name << ": technical issue reported. Staff checking equipment." << std::endl;
    }
    else if (dynamic_cast<const ResumptionNotice*>(&notice) != nullptr)
    {
        std::cout << "[Cosplay Meetup Point] " << name << ": normal operations may resume." << std::endl;
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
        std::cout << "[Cosplay Meetup Point] " << name << ": notice acknowledged." << std::endl;
    }

}

CosplayMeetupPoint::~CosplayMeetupPoint() {}
