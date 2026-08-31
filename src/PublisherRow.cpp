#include "PublisherRow.h"
#include "Notice.h"
#include <iostream>

PublisherRow::PublisherRow(const std::string& hallName) : EventGroup(hallName) {}

void PublisherRow::update(const Notice& notice)
{
    std::cout << "[Publisher Row] " << name << " received notice: " << notice.getMessage() << " (severity: " << notice.getSeverity() << ")" << std::endl;

    if (dynamic_cast<const EvacuationNotice*>(&notice) != nullptr)
    {
        std::cout << "[Publisher Row] Emergency evacuation procedures activated." << std::endl;
    }
    else if (dynamic_cast<const TechnicalOutage*>(&notice) != nullptr)
    {
        std::cout << "[Publisher Row] Technical teams have been notified." << std::endl;
    }

    notify(notice);
}

PublisherRow::~PublisherRow() {}