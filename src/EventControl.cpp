#include "EventControl.h"
#include "Notice.h"
#include <iostream>

EventControl::EventControl(const std::string& controlName) : name(controlName) {}

void EventControl::issueNotice(const Notice& notice) 
{
    std::cout << "[EventControl] " << name << " issuing notice: " << notice.getMessage() << " (severity " << notice.getSeverity() << ")" << std::endl;
    notify(notice);
}

const std::string& EventControl::getName() const 
{
    return name;
}

EventControl::~EventControl() {}