#include "TournamentHall.h"
#include "Notice.h"
#include <iostream>

TournamentHall::TournamentHall(const std::string& hallName) : EventGroup(hallName) {}

void TournamentHall::update(const Notice& notice)
{
    std::cout << "[Tournament Hall] " << name << " received notice: " << notice.getMessage() << " (severity: " << notice.getSeverity() << ")" << std::endl;

    if (dynamic_cast<const EvacuationNotice*>(&notice) != nullptr)
    {
        std::cout << "[Tournament Hall] Emergency evacuation procedures activated." << std::endl;
    }
    else if (dynamic_cast<const TechnicalOutage*>(&notice) != nullptr)
    {
        std::cout << "[Tournament Hall] Technical teams have been notified." << std::endl;
    }

    notify(notice);
}

TournamentHall::~TournamentHall() {}