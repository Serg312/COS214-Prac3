#include "TournamentStage.h"
#include "Notice.h"
#include <iostream>

TournamentStage::TournamentStage(const std::string& stageName, int audienceCapacity) : EventUnit(stageName, audienceCapacity), matchInProgress(false) {}

void TournamentStage::open() 
{
    isOpen = true;
    matchInProgress = true;
    std::cout << "[TournamentStage] " << name << ": match clock started, competitors on stage." << std::endl;
}

void TournamentStage::close() 
{
    if (matchInProgress) 
    {
        std::cout << "[TournamentStage] " << name << ": match in progress - pausing and forfeiting current match." << std::endl;
        matchInProgress = false;
    }
    isOpen = false;
    std::cout << "[TournamentStage] " << name << ": stage closed." << std::endl;
}

void TournamentStage::reportStatus() const 
{
    std::cout << "TournamentStage \"" << name << "\" - " << (isOpen ? "OPEN" : "CLOSED") << ", match in progress: " << (matchInProgress ? "yes" : "no") << ", capacity: " << capacity << std::endl;
}

void TournamentStage::update(const Notice& notice)
{
    std::cout << "[Booth] " << name << " received notice: " << notice.getMessage() << std::endl;

    if (dynamic_cast<const EvacuationNotice*>(&notice) != nullptr)
    {
        std::cout << "[Booth] " << name << ": Evacuation, closing stage immediately." << std::endl;
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

TournamentStage::~TournamentStage() {}
