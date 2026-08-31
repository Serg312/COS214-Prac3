#ifndef COMMUNITYZONE_H
#define COMMUNITYZONE_H

#include "EventGroup.h"
#include "Observer.h"
#include "Subject.h"

class Notice;

class CommunityZone : public EventGroup, public Observer, public Subject
{
    public:
        CommunityZone(const std::string& zoneName);
        void update(const Notice& notice) override;
        virtual ~CommunityZone();
};

#endif