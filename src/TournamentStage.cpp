#include "TournamentStage.h"
#include <iostream>

TournamentStage::TournamentStage(const std::string& stageName, int audienceCapacity)
    : EventUnit(stageName, audienceCapacity), matchInProgress(false) {}

void TournamentStage::open() {
    isOpen = true;
    matchInProgress = true;
    std::cout << "[TournamentStage] " << name << ": match clock started, competitors on stage." << std::endl;
}

void TournamentStage::close() {
    if (matchInProgress) {
        std::cout << "[TournamentStage] " << name << ": match in progress - pausing and forfeiting current match." << std::endl;
        matchInProgress = false;
    }
    isOpen = false;
    std::cout << "[TournamentStage] " << name << ": stage closed." << std::endl;
}

void TournamentStage::reportStatus() const {
    std::cout << "TournamentStage \"" << name << "\" - "
              << (isOpen ? "OPEN" : "CLOSED")
              << ", match in progress: " << (matchInProgress ? "yes" : "no")
              << ", capacity: " << capacity << std::endl;
}

TournamentStage::~TournamentStage() {}
