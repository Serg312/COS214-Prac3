#ifndef EVENTGROUP_H
#define EVENTGROUP_H

#include "EventComponent.h"
#include <vector>

class EventGroup : public EventComponent 
{
    private:
        std::vector<EventComponent*> children;
    public:
        EventGroup(const std::string& groupName);
        void add(EventComponent* component);
        bool remove(EventComponent* component);
        void open() override;
        void close() override;
        void reportStatus() const override;
        int getCapacity() const override;
        virtual ~EventGroup();
};

#endif
