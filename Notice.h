#ifndef NOTICE_H
#define NOTICE_H

#include <string>

class Notice {
protected:
    std::string message;
    int severity;

public:
    Notice(const std::string& msg, int sev);
    virtual ~Notice() = default;

    std::string getMessage() const;
    int getSeverity() const;
};

// 1. Safety-Related
class EvacuationNotice : public Notice {
public:
    EvacuationNotice(const std::string& msg = "IMMEDIATE EVACUATION REQUIRED!");
};

// 2. Capacity-Related
class CapacityWarning : public Notice {
public:
    CapacityWarning(const std::string& msg = "Area capacity limit reached.");
};

// 3. Operational / Technical
class TechnicalOutage : public Notice {
public:
    TechnicalOutage(const std::string& msg = "Technical outage reported.");
};

// 4. Capacity-Related
class QueueOverflowAlert : public Notice {
public:
    QueueOverflowAlert(const std::string& msg = "Queue lines overflowing.");
};

// 5. Ordinary Operational
class ResumptionNotice : public Notice {
public:
    ResumptionNotice(const std::string& msg = "Normal operations resumed.");
};

// 6. Ordinary Operational
class OpenNotice : public Notice {
public:
    OpenNotice(const std::string& msg = "Facility is now OPEN.");
};

#endif // NOTICE_H