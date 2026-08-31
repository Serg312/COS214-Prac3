#ifndef QUEUEMANAGEMENTPOINT_H
#define QUEUEMANAGEMENTPOINT_H

#include "EventUnit.h"
#include "Observer.h"

class QueueManagementPoint : public EventUnit, public Observer
{
    private:
        int queueLength;
    public:
        QueueManagementPoint(const std::string& pointName, int maxQueueLength);
        void open() override;
        void close() override;
        void reportStatus() const override;
        void update(const Notice& notice) override;
        virtual ~QueueManagementPoint();
};

#endif
