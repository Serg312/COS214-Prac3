#ifndef COMPONENTUTILS_H
#define COMPONENTUTILS_H

class EventComponent;
class EventGroup;

/**
 * @brief Reassigns an EventComponent from one EventGroup to another.
 *
 * This function attempts to remove the specified EventComponent from the 'from' EventGroup and add it to the 'to' EventGroup.
 * It returns true if the reassignment is successful, and false if either the removal or addition fails.
 *
 * @param unit Pointer to the EventComponent to be reassigned.
 * @param from Pointer to the EventGroup from which the component will be removed.
 * @param to Pointer to the EventGroup to which the component will be added.
 * @return true if reassignment is successful, false otherwise.
 */
bool reassignComponent(EventComponent* unit, EventGroup* from, EventGroup* to);

#endif // COMPONENTUTILS_H
