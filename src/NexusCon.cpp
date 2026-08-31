#include "NexusCon.h"
#include "Notice.h"
#include <iostream>

NexusCon::NexusCon(const std::string& eventName) : EventGroup(eventName) {}

void NexusCon::update(const Notice& notice)
{
    std::cout << "[NexusCon] " << name << " received notice: " << notice.getMessage() << " (severity: " << notice.getSeverity() << ")" << std::endl;
    notify(notice);
}

NexusCon::~NexusCon() {}