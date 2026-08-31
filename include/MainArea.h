#ifndef MAINAREA_H
#define MAINAREA_H

#include "EventGroup.h"
#include "Observer.h"
#include "Subject.h"

class Notice;

class MainArea : public EventGroup, public Observer, public Subject
{
    public:
        MainArea(const std::string& areaName);
        void update(const Notice& notice) override;
        virtual ~MainArea();
};

#endif