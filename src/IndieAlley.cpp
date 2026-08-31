#include "IndieAlley.h"
#include "Notice.h"
#include <iostream>

IndieAlley::IndieAlley(const std::string& hallName) : EventGroup(hallName) {}

void IndieAlley::update(const Notice& notice)
{
    std::cout << "[Indie Alley] " << name << " received notice: " << notice.getMessage() << " (severity: " << notice.getSeverity() << ")" << std::endl;

    if (dynamic_cast<const EvacuationNotice*>(&notice) != nullptr)
    {
        std::cout << "[Indie Alley] Emergency evacuation procedures activated." << std::endl;
    }
    else if (dynamic_cast<const TechnicalOutage*>(&notice) != nullptr)
    {
        std::cout << "[Indie Alley] Technical teams have been notified." << std::endl;
    }

    notify(notice);
}

IndieAlley::~IndieAlley() {}