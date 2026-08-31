#ifndef EVENTCONTROL_H
#define EVENTCONTROL_H

#include "Subject.h"

class Notice;

class EventControl : public Subject
{
    public:
        EventControl();
        void issueNotice(const Notice& notice);
        virtual ~EventControl();
};

#endif