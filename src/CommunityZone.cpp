#include "CommunityZone.h"
#include "Notice.h"
#include <iostream>

CommunityZone::CommunityZone(const std::string& hallName) : EventGroup(hallName) {}

void CommunityZone::update(const Notice& notice)
{
    std::cout << "[Community Zone] " << name << " received notice: " << notice.getMessage() << " (severity: " << notice.getSeverity() << ")" << std::endl;

    if (dynamic_cast<const EvacuationNotice*>(&notice) != nullptr)
    {
        std::cout << "[Community Zone] Emergency evacuation procedures activated." << std::endl;
    }
    else if (dynamic_cast<const TechnicalOutage*>(&notice) != nullptr)
    {
        std::cout << "[Community Zone] Technical teams have been notified." << std::endl;
    }

    notify(notice);
}

CommunityZone::~CommunityZone() {}