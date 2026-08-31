#ifndef QUEUEMANAGEMENTPOINT_H
#define QUEUEMANAGEMENTPOINT_H

#include "EventUnit.h"

class QueueManagementPoint : public EventUnit 
{
    private:
        int queueLength;
    public:
        QueueManagementPoint(const std::string& pointName, int maxQueueLength);
        void open() override;
        void close() override;
        void reportStatus() const override;
        virtual ~QueueManagementPoint();
};

#endif
