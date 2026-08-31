#ifndef CASTERBOOTH_H
#define CASTERBOOTH_H

#include "EventUnit.h"
#include "Observer.h"

class CasterBooth : public EventUnit, public Observer
{
    private:
        bool isLive;       
        int viewerCount;   
    public:
        CasterBooth(const std::string& boothName, int crewCapacity);
        void open() override;
        void close() override;
        void reportStatus() const override;
        void update(const Notice& notice) override;
        virtual ~CasterBooth();
};

#endif
