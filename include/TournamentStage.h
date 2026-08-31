#ifndef TOURNAMENTSTAGE_H
#define TOURNAMENTSTAGE_H

#include "EventUnit.h"
#include "Observer.h"

class TournamentStage : public EventUnit, public Observer
{
    private:
        bool matchInProgress;
    public:
        TournamentStage(const std::string& stageName, int audienceCapacity);
        void open() override;
        void close() override;
        void reportStatus() const override;
        void update(const Notice& notice) override;
        virtual ~TournamentStage();
};

#endif
