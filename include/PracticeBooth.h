#ifndef PRACTICEBOOTH_H
#define PRACTICEBOOTH_H

#include "EventUnit.h"
#include "Observer.h"

class Notice;

class PracticeBooth : public EventUnit, public Observer
{
    private:
        bool occupied;
    public:
        PracticeBooth(const std::string& boothName, int playerCapacity);
        void open() override;
        void close() override;
        void reportStatus() const override;
        void update(const Notice& notice) override;
        virtual ~PracticeBooth();
};

#endif  