#include "PracticeZone.h"
#include "Notice.h"
#include <iostream>

PracticeZone::PracticeZone(const std::string& hallName) : EventGroup(hallName) {}

void PracticeZone::update(const Notice& notice)
{
    std::cout << "[Practice Zone] " << name << " received notice: " << notice.getMessage() << " (severity: " << notice.getSeverity() << ")" << std::endl;

    if (dynamic_cast<const EvacuationNotice*>(&notice) != nullptr)
    {
        std::cout << "[Practice Zone] Emergency evacuation procedures activated." << std::endl;
    }
    else if (dynamic_cast<const TechnicalOutage*>(&notice) != nullptr)
    {
        std::cout << "[Practice Zone] Technical teams have been notified." << std::endl;
    }

    notify(notice);
}

PracticeZone::~PracticeZone() {}