#ifndef INFODESK_H
#define INFODESK_H

#include "EventUnit.h"
#include "Observer.h"

class Notice;

class InfoDesk : public EventUnit, public Observer
{
    private:
        bool staffAvailable;
    public:
        InfoDesk(const std::string& deskName, int visitorCapacity);
        void open() override;
        void close() override;
        void reportStatus() const override;
        void update(const Notice& notice) override;
        virtual ~InfoDesk();
};

#endif