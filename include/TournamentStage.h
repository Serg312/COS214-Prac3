#ifndef TOURNAMENTSTAGE_H
#define TOURNAMENTSTAGE_H

#include "EventUnit.h"
#include "Observer.h"

/**
 * @brief Represents a tournament stage within the event, capable of receiving notices and reporting its status.
 *
 * The TournamentStage class inherits from EventUnit and Observer, allowing it to be part of the event's unit structure,
 * receive notifications about various events or changes in the system, and report its own status accordingly.
 */
class TournamentStage : public EventUnit, public Observer
{
    private:
        /// @brief Indicates whether a match is currently in progress on the tournament stage.
        bool matchInProgress;
    public:
        /// @brief Constructs a new TournamentStage instance.
        /// @param stageName The name of the tournament stage, used for identification and reporting.
        /// @param audienceCapacity The maximum number of spectators the stage can accommodate.
        TournamentStage(const std::string& stageName, int audienceCapacity);
        /// @brief Opens the tournament stage, allowing matches to be held and spectators to enter.
        void open() override;
        /// @brief Closes the tournament stage, preventing further matches and spectator entry.
        void close() override;
        /// @brief Reports the current status of the tournament stage, including match progress and audience capacity.
        void reportStatus() const override;
        /// @brief Updates the tournament stage's state based on a received notice.
        void update(const Notice& notice) override;
        /// @brief Destructor for the TournamentStage class.
        virtual ~TournamentStage();
};

#endif
