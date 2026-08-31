#include "Booth.h"
#include <iostream>

Booth::Booth(const std::string& boothName, int visitorCapacity) : EventUnit(boothName, visitorCapacity), staffed(false), footTraffic(0) {}

void Booth::open() 
{
    isOpen = true;
    staffed = true;
    footTraffic = 0;
    std::cout << "[Booth] " << name << ": staff arrived, merchandise and banners available." << std::endl;
}

void Booth::close() 
{
    std::cout << "[Booth] " << name << ": merchandise packed away." << std::endl;
    staffed = false;
    footTraffic = 0;
    isOpen = false;
}

void Booth::reportStatus() const 
{
    std::cout << "Booth \"" << name << "\" - " << (staffed ? "STAFFED" : "UNSTAFFED") << ", foot traffic: " << footTraffic << ", capacity: " << capacity << std::endl;
}

Booth::~Booth() {}
