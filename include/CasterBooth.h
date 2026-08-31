#ifndef CASTERBOOTH_H
#define CASTERBOOTH_H

#include "EventUnit.h"

class CasterBooth : public EventUnit 
{
    private:
        bool isLive;       
        int viewerCount;   
    public:
        CasterBooth(const std::string& boothName, int crewCapacity);
        void open() override;
        void close() override;
        void reportStatus() const override;
        virtual ~CasterBooth();
};

#endif
