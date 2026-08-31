#ifndef EVENTGROUP_H
#define EVENTGROUP_H

#include "EventComponent.h"
#include <vector>

/**
 * @brief Represents a group of event components within the event system.
 */
class EventGroup : public EventComponent 
{
    private:
        /// @brief The list of child components within the event group.
        std::vector<EventComponent*> children;
    public:
        /**
         * @brief Constructs a new EventGroup instance.
         * @param groupName The name of the event group, used for identification and reporting.
         */
        EventGroup(const std::string& groupName);
        /// @brief Adds a component to the event group.
        void add(EventComponent* component);
        /// @brief Removes a component from the event group.
        bool remove(EventComponent* component);
        /// @brief Opens all components within the event group.
        void open() override;
        /// @brief Closes all components within the event group.
        void close() override;
        /// @brief Reports the current status of the event group.
        void reportStatus() const override;
        /// @brief Gets the capacity of the event group.
        int getCapacity() const override;
        /// @brief Destructor for the EventGroup class.
        virtual ~EventGroup();
};

#endif
