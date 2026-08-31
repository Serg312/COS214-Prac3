#ifndef INDIEBOOTH_H
#define INDIEBOOTH_H

#include "EventUnit.h"
#include "Observer.h"

class Notice;

class IndieBooth : public EventUnit, public Observer
{
    private:
        bool developerPresent;
    public:
        IndieBooth(const std::string& boothName, int visitorCapacity);
        void open() override;
        void close() override;
        void reportStatus() const override;
        void update(const Notice& notice) override;
        virtual ~IndieBooth();
};

#endif