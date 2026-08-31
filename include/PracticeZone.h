#ifndef PRACTICEZONE_H
#define PRACTICEZONE_H

#include "EventGroup.h"
#include "Observer.h"
#include "Subject.h"

class Notice;

class PracticeZone : public EventGroup, public Observer, public Subject
{
    public:
        PracticeZone(const std::string& zoneName);
        void update(const Notice& notice) override;
        virtual ~PracticeZone();
};

#endif