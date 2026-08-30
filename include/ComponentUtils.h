#ifndef COMPONENTUTILS_H
#define COMPONENTUTILS_H

class EventComponent;
class EventGroup;

/**
 * @brief Safely reassigns a component from one EventGroup to another.
 *
 * Performs three things atomically from the caller's perspective:
 *   1. Detaches @p unit from @p from's ownership (composite tree) —
 *      does NOT delete it.
 *   2. If @p unit also participates as an Observer, deregisters it from
 *      @p from's Subject role and re-registers it with @p to's.
 *   3. Attaches @p unit to @p to's ownership.
 *
 * Works with any EventGroup subclass (TournamentHall, ExpoFloor,
 * CommunityZone, MainArea, etc.) since it only calls the public
 * add/remove/attach/detach operations — no downcasting required.
 *
 * If @p unit is not currently owned by @p from, this function does
 * nothing (no partial transfer, no leak, no double-registration).
 *
 * @param unit The component being moved (e.g. QueueManagementPoint).
 *             Must not be nullptr.
 * @param from The EventGroup that currently owns @p unit. Must not be
 *             nullptr.
 * @param to   The EventGroup that will own @p unit afterwards. Must not
 *             be nullptr.
 * @return true if the transfer happened, false if @p unit was not
 *         actually owned by @p from (or any argument was nullptr).
 */
bool reassignComponent(EventComponent* unit, EventGroup* from, EventGroup* to);

#endif // COMPONENTUTILS_H
