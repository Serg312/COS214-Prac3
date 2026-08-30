#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>

class Observer;
class Notice;

/**
 * @brief Subject role of the Observer pattern.
 *
 * Stores non-owning pointers to registered Observers. Subject does not
 * delete its observers on destruction — it only clears its
 * registration list. Observer object lifetime is managed by whatever
 * owns it in the Composite tree instead, so a Subject that is also a
 * Composite-owned child is never deleted twice.
 */
class Subject {
protected:
    /// Non-owning pointers — Subject does not own its observers.
    std::vector<Observer*> observers;

public:
    /// @brief Clears the registration list without deleting observers.
    virtual ~Subject();
    /**
     * @brief Registers an observer for future notifications.
     * @param observer Observer to register. Must not be nullptr.
     *
     * Policy: a duplicate attach() of the same pointer is ignored.
     */
    virtual void attach(Observer* observer);
        /**
     * @brief Deregisters an observer.
     * @param observer Observer to remove. If not currently registered, this is a no-op.
     */
    virtual void detach(Observer* observer);
    /**
     * @brief Notifies all currently registered observers.
     * @param notice The notice being issued to every registered observer.
     */
    virtual void notify(const Notice& notice);
};

#endif