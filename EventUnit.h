#ifndef EVENTUNIT_H
#define EVENTUNIT_H

#include "EventComponent.h"

class EventUnit : public EventComponent 
{
    protected:
        int capacity;  
        bool isOpen;   
    public:
        EventUnit(const std::string& unitName, int unitCapacity);
        int getCapacity() const override;
        virtual ~EventUnit();
};

#endif
