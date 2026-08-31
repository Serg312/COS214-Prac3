#ifndef BOOTH_H
#define BOOTH_H

#include "EventUnit.h"

class Booth : public EventUnit 
{
    private:
        bool staffed;    
        int footTraffic;   
    public:
        Booth(const std::string& boothName, int visitorCapacity);
        void open() override;
        void close() override;
        void reportStatus() const override;
        virtual ~Booth();
};

#endif
