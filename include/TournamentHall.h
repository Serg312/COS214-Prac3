#ifndef TOURNAMENTHALL_H
#define TOURNAMENTHALL_H

#include "EventGroup.h"
#include "Observer.h"
#include "Subject.h"

/**
 * @brief Allows use of the notice classes without including the entire Notice.h header, reducing compilation dependencies.
 */
class Notice;

/**
 * @brief Represents a tournament hall within the event, capable of receiving notices and reporting its status.
 *
 * The TournamentHall class inherits from EventGroup, Observer, and Subject, allowing it to be part of the event's group structure,
 * receive notifications about various events or changes in the system, report its own status accordingly, and manage a list of observers.
 */
class TournamentHall : public EventGroup, public Observer, public Subject
{
    public:
        ///@brief Constructs a new TournamentHall instance.
        ///@param hallName The name of the tournament hall, used for identification and reporting.
        TournamentHall(const std::string& hallName);
        /// @brief Updates the tournament hall based on the received notice.
        /// @param notice The notice received by the tournament hall.
        void update(const Notice& notice) override;
        /// @brief Destructor for the TournamentHall class.
        virtual ~TournamentHall();
};

#endif