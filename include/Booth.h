#ifndef BOOTH_H
#define BOOTH_H

#include "EventUnit.h"
#include "Observer.h"

class Booth : public EventUnit, public Observer
{
    private:
        bool staffed;    
        int footTraffic;   
    public:
        Booth(const std::string& boothName, int visitorCapacity);
        void open() override;
        void close() override;
        void reportStatus() const override;
        void update(const Notice& notice) override;
        virtual ~Booth();
};

#endif
