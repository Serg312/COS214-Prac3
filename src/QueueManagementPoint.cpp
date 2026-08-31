#include "QueueManagementPoint.h"
#include <iostream>

QueueManagementPoint::QueueManagementPoint(const std::string& pointName, int maxQueueLength)
    : EventUnit(pointName, maxQueueLength), queueLength(0) {}

void QueueManagementPoint::open() {
    queueLength = 0;
    isOpen = true;
    std::cout << "[QueueManagementPoint] " << name << ": queue line opened." << std::endl;
}

void QueueManagementPoint::close() {
    if (queueLength > 0) {
        std::cout << "[QueueManagementPoint] " << name << ": clearing queue of "
                  << queueLength << " waiting attendees." << std::endl;
    }
    queueLength = 0;
    isOpen = false;
    std::cout << "[QueueManagementPoint] " << name << ": queue line closed." << std::endl;
}

void QueueManagementPoint::reportStatus() const {
    std::cout << "QueueManagementPoint \"" << name << "\" - "
              << (isOpen ? "OPEN" : "CLOSED")
              << ", currently waiting: " << queueLength
              << ", max safe length: " << capacity << std::endl;
}

QueueManagementPoint::~QueueManagementPoint() {}
