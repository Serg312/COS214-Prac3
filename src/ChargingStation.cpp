#include "ChargingStation.h"
#include <iostream>

ChargingStation::ChargingStation(const std::string& stationName, int portCount)
    : EventUnit(stationName, portCount), totalPorts(portCount), activePorts(0) {}

void ChargingStation::open() {
    activePorts = totalPorts;
    isOpen = true;
    std::cout << "[ChargingStation] " << name << ": all " << totalPorts << " ports now supplying power." << std::endl;
}

void ChargingStation::close() {
    std::cout << "[ChargingStation] " << name << ": powering down ports." << std::endl;
    activePorts = 0;
    isOpen = false;
}

void ChargingStation::reportStatus() const {
    std::cout << "ChargingStation \"" << name << "\" - "
              << activePorts << "/" << totalPorts << " ports active"
              << ", capacity: " << capacity << std::endl;
}

ChargingStation::~ChargingStation() {}
