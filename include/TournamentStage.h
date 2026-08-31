#ifndef TOURNAMENTSTAGE_H
#define TOURNAMENTSTAGE_H

#include "EventUnit.h"

class TournamentStage : public EventUnit 
{
    private:
        bool matchInProgress;
    public:
        TournamentStage(const std::string& stageName, int audienceCapacity);
        void open() override;
        void close() override;
        void reportStatus() const override;
        virtual ~TournamentStage();
};

#endif
