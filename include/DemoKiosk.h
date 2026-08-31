#ifndef DEMOKIOSK_H
#define DEMOKIOSK_H

#include "EventUnit.h"
#include "Observer.h"

class DemoKiosk : public EventUnit, public Observer
{
    private:
        int totalUnits;   
        int poweredUnits;  
    public:
        DemoKiosk(const std::string& kioskName, int hardwareUnits);
        void open() override;
        void close() override;
        void reportStatus() const override;
        void update(const Notice& notice) override;
        virtual ~DemoKiosk();
};

#endif
