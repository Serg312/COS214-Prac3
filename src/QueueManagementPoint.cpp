#include "QueueManagementPoint.h"
#include "Notice.h"
#include <iostream>

QueueManagementPoint::QueueManagementPoint(const std::string& pointName, int maxQueueLength) : EventUnit(pointName, maxQueueLength), queueLength(0) {}

void QueueManagementPoint::open() 
{
    queueLength = 0;
    isOpen = true;
    std::cout << "[QueueManagementPoint] " << name << ": queue opened." << std::endl;
}

void QueueManagementPoint::close() 
{
    if (queueLength > 0) 
    {
        std::cout << "[QueueManagementPoint] " << name << ": clearing queue of " << queueLength << " attendees." << std::endl;
    }
    queueLength = 0;
    isOpen = false;
    std::cout << "[QueueManagementPoint] " << name << ": queue closed." << std::endl;
}

void QueueManagementPoint::reportStatus() const 
{
    std::cout << "QueueManagementPoint \"" << name << "\" - " << (isOpen ? "OPEN" : "CLOSED") << ", currently waiting: " << queueLength << ", max length: " << capacity << std::endl;
}

void QueueManagementPoint::update(const Notice& notice)
{
    std::cout << "[Booth] " << name << " received notice: " << notice.getMessage() << std::endl;

    if (dynamic_cast<const EvacuationNotice*>(&notice) != nullptr)
    {
        std::cout << "[Booth] " << name << ": Evacuation, closing off queue immediately." << std::endl;
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

QueueManagementPoint::~QueueManagementPoint() {}
