#include "ExpoFloor.h"
#include "Notice.h"
#include <iostream>

ExpoFloor::ExpoFloor(const std::string& hallName) : EventGroup(hallName) {}

void ExpoFloor::update(const Notice& notice)
{
    std::cout << "[Expo Floor] " << name << " received notice: " << notice.getMessage() << " (severity: " << notice.getSeverity() << ")" << std::endl;

    if (dynamic_cast<const EvacuationNotice*>(&notice) != nullptr)
    {
        std::cout << "[Expo Floor] Emergency evacuation procedures activated." << std::endl;
    }
    else if (dynamic_cast<const TechnicalOutage*>(&notice) != nullptr)
    {
        std::cout << "[Expo Floor] Technical teams have been notified." << std::endl;
    }

    notify(notice);
}

ExpoFloor::~ExpoFloor() {}