#ifndef FIRSTAIDPOINT_H
#define FIRSTAIDPOINT_H

#include "EventUnit.h"
#include "Observer.h"

class Notice;

class FirstAidPoint : public EventUnit, public Observer
{
    private:
        bool emergencyReady;
    public:
        FirstAidPoint(const std::string& pointName, int patientCapacity);
        void open() override;
        void close() override;
        void reportStatus() const override;
        void update(const Notice& notice) override;
        virtual ~FirstAidPoint();
};

#endif