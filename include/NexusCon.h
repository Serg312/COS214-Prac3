#ifndef NEXUSCON_H
#define NEXUSCON_H

#include "EventGroup.h"
#include "Observer.h"
#include "Subject.h"

class Notice;

class NexusCon : public EventGroup, public Observer, public Subject
{
    public:
        NexusCon(const std::string& eventName);
        void update(const Notice& notice) override;
        virtual ~NexusCon();
};

#endif