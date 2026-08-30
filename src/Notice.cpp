#include "Notice.h"

Notice::Notice(const std::string& msg, int sev) : message(msg), severity(sev) {}

std::string Notice::getMessage() const { return message; }
int Notice::getSeverity() const { return severity; }

EvacuationNotice::EvacuationNotice(const std::string& msg) 
    : Notice(msg, 10) {}

CapacityWarning::CapacityWarning(const std::string& msg) 
    : Notice(msg, 5) {}

TechnicalOutage::TechnicalOutage(const std::string& msg) 
    : Notice(msg, 7) {}

QueueOverflowAlert::QueueOverflowAlert(const std::string& msg) 
    : Notice(msg, 4) {}

ResumptionNotice::ResumptionNotice(const std::string& msg) 
    : Notice(msg, 1) {}

OpenNotice::OpenNotice(const std::string& msg) 
    : Notice(msg, 2) {}