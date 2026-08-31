#ifndef EVENTCONTROL_H
#define EVENTCONTROL_H

#include "Subject.h"
#include <string>

/**
 * @brief Allows use of the notice classes without including the entire Notice.h header, reducing compilation dependencies.
 */
class Notice;
/**
 * @brief Manages the issuance of notices to registered observers within the event system.
 *
 * The EventControl class inherits from Subject, allowing it to maintain a list of observers and notify them of various
 * notices or events. It serves as the central point for issuing notices to all registered observers in the system.
 */
class EventControl : public Subject {
private:
    /// Human-readable name for this control point (e.g. "NexusCon Control").
    std::string name;

public:
    /**
     * @brief Construct a new EventControl.
     * @param controlName Human-readable name for this control point.
     */
    explicit EventControl(const std::string& controlName);

    /**
     * @brief Issue a notice to every currently registered observer.
     *
     * Thin, semantically-named wrapper around Subject::notify(),
     * representing the control centre actively broadcasting a change
     * (e.g. "issue an evacuation notice") rather than a generic call.
     *
     * @param notice The notice to broadcast to all registered observers.
     */
    void issueNotice(const Notice& notice);

    /**
     * @brief Get the name of this control point.
     * @return const std::string& This control point's name.
     */
    const std::string& getName() const;

    /**
     * @brief Virtual destructor.
     */
    virtual ~EventControl();
};

#endif // EVENTCONTROL_H