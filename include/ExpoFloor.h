#ifndef EXPOFLOOR_H
#define EXPOFLOOR_H

#include "EventGroup.h"
#include "Observer.h"
#include "Subject.h"

class Notice;

class ExpoFloor : public EventGroup, public Observer, public Subject
{
    public:
        ExpoFloor(const std::string& floorName);
        void update(const Notice& notice) override;
        virtual ~ExpoFloor();
};

#endif