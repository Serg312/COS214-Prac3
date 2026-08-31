#ifndef TOURNAMENTHALL_H
#define TOURNAMENTHALL_H

#include "EventGroup.h"
#include "Observer.h"
#include "Subject.h"

class Notice;

class TournamentHall : public EventGroup, public Observer, public Subject
{
    public:
        TournamentHall(const std::string& hallName);
        void update(const Notice& notice) override;
        virtual ~TournamentHall();
};

#endif