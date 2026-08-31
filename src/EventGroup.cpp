#include "EventGroup.h"
#include <algorithm>
#include <iostream>

EventGroup::EventGroup(const std::string& groupName) : EventComponent(groupName) {}

void EventGroup::add(EventComponent* component) {
    if (component != nullptr) {
        children.push_back(component);
    }
}

void EventGroup::remove(EventComponent* component) {
    children.erase(std::remove(children.begin(), children.end(), component), children.end());
}

void EventGroup::open() {
    std::cout << "[EventGroup] Opening area: " << name << std::endl;
    for (EventComponent* child : children) {
        child->open();
    }
}

void EventGroup::close() {
    std::cout << "[EventGroup] Closing area: " << name << std::endl;
    for (EventComponent* child : children) {
        child->close();
    }
}

void EventGroup::reportStatus() const {
    std::cout << "== Area: " << name << " ==" << std::endl;
    for (EventComponent* child : children) {
        child->reportStatus();
    }
}

int EventGroup::getCapacity() const {
    int total = 0;
    for (EventComponent* child : children) {
        total += child->getCapacity();
    }
    return total;
}

EventGroup::~EventGroup() {
    for (EventComponent* child : children) {
        delete child;
    }
    children.clear();
    std::cout << "[EventGroup] Destroyed area and released its subtree: " << name << std::endl;
}
