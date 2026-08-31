#include "MainArea.h"
#include "Notice.h"
#include <iostream>

MainArea::MainArea(const std::string& hallName) : EventGroup(hallName) {}

void MainArea::update(const Notice& notice)
{
    std::cout << "[Main Area] " << name << " received notice: " << notice.getMessage() << " (severity: " << notice.getSeverity() << ")" << std::endl;

    if (dynamic_cast<const EvacuationNotice*>(&notice) != nullptr)
    {
        std::cout << "[Main Area] Emergency evacuation procedures activated." << std::endl;
    }
    else if (dynamic_cast<const TechnicalOutage*>(&notice) != nullptr)
    {
        std::cout << "[Main Area] Technical teams have been notified." << std::endl;
    }

    notify(notice);
}

MainArea::~MainArea() {}