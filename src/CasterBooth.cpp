#include "CasterBooth.h"
#include <iostream>

CasterBooth::CasterBooth(const std::string& boothName, int crewCapacity) : EventUnit(boothName, crewCapacity), isLive(false), viewerCount(0) {}

void CasterBooth::open() 
{
    isOpen = true;
    isLive = true;
    viewerCount = 100; 
    std::cout << "[CasterBooth] " << name << ": going live, viewers joining the stream." << std::endl;
}

void CasterBooth::close() 
{
    isLive = false;
    viewerCount = 0;
    isOpen = false;
    std::cout << "[CasterBooth] " << name << ": broadcast ended." << std::endl;
}

void CasterBooth::reportStatus() const 
{
    std::cout << "CasterBooth \"" << name << "\" - " << (isLive ? "LIVE" : "OFFLINE") << ", viewers: " << viewerCount << ", capacity: " << capacity << std::endl;
}

CasterBooth::~CasterBooth() {}
