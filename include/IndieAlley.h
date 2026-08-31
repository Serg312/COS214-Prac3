#ifndef INDIEALLEY_H
#define INDIEALLEY_H

#include "EventGroup.h"
#include "Observer.h"
#include "Subject.h"

class Notice;

class IndieAlley : public EventGroup, public Observer, public Subject
{
    public:
        IndieAlley(const std::string& alleyName);
        void update(const Notice& notice) override;
        virtual ~IndieAlley();
};

#endif