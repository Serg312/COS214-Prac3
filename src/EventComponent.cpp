#include "EventComponent.h"

EventComponent::EventComponent(const std::string& componentName) : name(componentName) {}

const std::string& EventComponent::getName() const 
{
    return name;
}

EventComponent::~EventComponent() {}
