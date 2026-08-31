#ifndef PUBLISHERROW_H
#define PUBLISHERROW_H

#include "EventGroup.h"
#include "Observer.h"
#include "Subject.h"

class Notice;

class PublisherRow : public EventGroup, public Observer, public Subject
{
    public:
        PublisherRow(const std::string& rowName);
        void update(const Notice& notice) override;
        virtual ~PublisherRow();
};

#endif