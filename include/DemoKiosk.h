#ifndef DEMOKIOSK_H
#define DEMOKIOSK_H

#include "EventUnit.h"

class DemoKiosk : public EventUnit 
{
    private:
        int totalUnits;   
        int poweredUnits;  
    public:
        DemoKiosk(const std::string& kioskName, int hardwareUnits);
        void open() override;
        void close() override;
        void reportStatus() const override;
        virtual ~DemoKiosk();
};

#endif
