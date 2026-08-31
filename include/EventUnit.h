#ifndef EVENTUNIT_H
#define EVENTUNIT_H

#include "EventComponent.h"

/**
 * @brief Represents a unit within the event system, which has a capacity and can be opened or closed.
 *
 * The EventUnit class inherits from EventComponent and adds functionality for managing capacity and open/closed state.
 */
class EventUnit : public EventComponent 
{
    protected:
        /// @brief The capacity of the event unit.
        int capacity;  
        /// @brief Indicates whether the event unit is currently open or closed.
        bool isOpen;   
    public:
        /**
         * @brief Constructs a new EventUnit instance.
         * @param unitName The name of the event unit, used for identification and reporting.
         * @param unitCapacity The maximum capacity of the event unit.
         */
        EventUnit(const std::string& unitName, int unitCapacity);
        /// @brief Gets the capacity of the event unit.
        int getCapacity() const override;
        /// @brief Destructor for the EventUnit class.
        virtual ~EventUnit();
};

#endif
