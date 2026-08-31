#include "EventUnit.h"

EventUnit::EventUnit(const std::string& unitName, int unitCapacity) : EventComponent(unitName), capacity(unitCapacity), isOpen(false) {}

int EventUnit::getCapacity() const 
{
    return capacity;
}

EventUnit::~EventUnit() {}
