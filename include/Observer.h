#ifndef OBSERVER_H
#define OBSERVER_H

/**
 * @brief Observer role of the Observer pattern.
 *
 * Anything that must react to a Notice implements this interface. A
 * class may be an Observer of one collaboration and a Subject of
 * another (e.g. a zone observes its parent zone but is itself a
 * Subject to its own children) — that dual role is intentional, not a
 * design smell.
 */

class Notice;

class Observer {
public:
    /// @brief Virtual destructor
    virtual ~Observer() = default;
    /**
     * @brief Called by a Subject when a Notice is issued (push model).
     * @param notice The notice carrying the relevant state. Non-owning reference — the Observer must not delete it.
     */
    virtual void update(const Notice& notice) = 0;
};

#endif