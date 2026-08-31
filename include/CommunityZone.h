#ifndef COMMUNITYZONE_H
#define COMMUNITYZONE_H

#include "EventGroup.h"
#include "Observer.h"
#include "Subject.h"

/**
 * @brief Allows use of the notice classes without including the entire Notice.h header, reducing compilation dependencies.
 */
class Notice;

/**
 * @brief Represents a community zone within the event, capable of receiving notices and reporting its status.
 *
 * The CommunityZone class inherits from EventGroup, Observer, and Subject, allowing it to be part of the event's unit structure,
 * receive notifications about various events or changes in the system, and notify its own observers of relevant updates.
 */
class CommunityZone : public EventGroup, public Observer, public Subject
{
    public:
        /**
         * @brief Constructs a new CommunityZone instance.
         * @param zoneName The name of the community zone, used for identification and reporting.
         */
        CommunityZone(const std::string& zoneName);
        /// @brief Updates the community zone's state based on a received notice.
        /// @param notice The notice containing information about the event or change.
        void update(const Notice& notice) override;
        /// @brief Destructor for the CommunityZone class.
        virtual ~CommunityZone();
};

#endif