#ifndef EVENTCOMPONENT_H
#define EVENTCOMPONENT_H

#include <string>

/**
 * @brief Represents a component within the event system.
 */
class EventComponent 
{
    protected:
        /// @brief The name of the event component.
        std::string name;
    public:
        /**
         * @brief Constructs a new EventComponent instance.
         * @param componentName The name of the event component, used for identification and reporting.
         */
        EventComponent(const std::string& componentName);
        /// @brief Opens the event component.
        virtual void open() = 0;
        /// @brief Closes the event component.
        virtual void close() = 0;
        /// @brief Reports the current status of the event component.
        virtual void reportStatus() const = 0;
        /// @brief Gets the capacity of the event component.
        virtual int getCapacity() const = 0;
        /// @brief Gets the name of the event component.
        const std::string& getName() const;
        /// @brief Destructor for the EventComponent class.
        virtual ~EventComponent();
};

#endif
