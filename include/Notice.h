#ifndef NOTICE_H
#define NOTICE_H

#include <string>

/**
 * @brief Base class for all event notices pushed through the Observer
 *        collaboration.
 *
 * A Notice is NexusCon's order/notice representation (see spec section 7,
 * final bullet): it carries the message and severity that get pushed to
 * every observer's update() call, rather than observers pulling state
 * back from the Subject (push model, Task 3.5).
 */

class Notice {
protected:

    /// human readable description of the notice
    std::string message;

    /// Severity level of the notice. Higher values indicate a more
    /// urgent notice (e.g. an evacuation is more severe than a
    /// schedule change).
    int severity;

public:
/**
     * @brief Constructs a Notice with a message and severity.
     * @param msg The human-readable notice text.
     * @param sev The severity level of this notice.
     */
    Notice(const std::string& msg, int sev);

    /// @brief Virtual destructor
    virtual ~Notice() = default;

    /**
     * @brief Returns this notice's message.
     * @return The human-readable notice text.
     */
    std::string getMessage() const;

    /**
     * @brief Returns this notice's severity level.
     * @return The severity level of this notice.
     */
    int getSeverity() const;
};

/**
 * @brief Safety-related notice: attendees/units must evacuate immediately. Defaults to the highest severity in the system.
 */
class EvacuationNotice : public Notice {
public:
    /**
     * @brief Constructs an EvacuationNotice.
     * @param msg The evacuation message. Defaults to a standard evacuation instruction if not provided.
     */
    EvacuationNotice(const std::string& msg = "IMMEDIATE EVACUATION REQUIRED!");
};

/**
 * @brief Capacity-related notice: an area is at or above its capacity
 *        threshold.
 */
class CapacityWarning : public Notice {
public:
    /**
     * @brief Constructs a CapacityWarning.
     * @param msg The capacity warning message. Defaults to a standard capacity-limit message if not provided.
     */
    CapacityWarning(const std::string& msg = "Area capacity limit reached.");
};

/**
 * @brief Operational/technical notice: equipment or connectivity failure at a unit or zone.
 */
class TechnicalOutage : public Notice {
public:
        /**
     * @brief Constructs a TechnicalOutage notice.
     * @param msg The outage message. Defaults to a generic technical outage message if not provided.
     */
    TechnicalOutage(const std::string& msg = "Technical outage reported.");
};

/**
 * @brief Capacity-related notice: a queue has grown beyond a manageable length.
 */
class QueueOverflowAlert : public Notice {
public:
    /**
     * @brief Constructs a QueueOverflowAlert.
     * @param msg The overflow message. Defaults to a generic queue overflow message if not provided.
     */
    QueueOverflowAlert(const std::string& msg = "Queue lines overflowing.");
};

/**
 * @brief Ordinary operational notice: signals recovery/resumption after a prior alert.
 */
class ResumptionNotice : public Notice {
public:
    /**
     * @brief Constructs a ResumptionNotice.
     * @param msg The resumption message. Defaults to a generic resumption message if not provided.
     */
    ResumptionNotice(const std::string& msg = "Normal operations resumed.");
};

/**
 * @brief Ordinary operational notice: signals that a facility/area has opened.
 */
class OpenNotice : public Notice {
public:
    /**
     * @brief Constructs an OpenNotice.
     * @param msg The open notice message. Defaults to a generic "now open" message if not provided.
     */
    OpenNotice(const std::string& msg = "Facility is now OPEN.");
};

#endif // NOTICE_H