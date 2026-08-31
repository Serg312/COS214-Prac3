#ifndef COSPLAYMEETUPPOINT_H
#define COSPLAYMEETUPPOINT_H

#include "EventUnit.h"
#include "Observer.h"

class Notice;

class CosplayMeetupPoint : public EventUnit, public Observer
{
    private:
        int participants;
    public:
        CosplayMeetupPoint(const std::string& pointName, int participantCapacity);
        void open() override;
        void close() override;
        void reportStatus() const override;
        void update(const Notice& notice) override;
        virtual ~CosplayMeetupPoint();
};

#endif