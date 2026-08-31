#ifndef INFODESK_H
#define INFODESK_H

#include "EventUnit.h"
#include "Observer.h"

/**
 * @brief Allows use of the notice classes without including the entire Notice.h header, reducing compilation dependencies.
 */
class Notice;

/**
 * @brief Represents an information desk within the event, capable of receiving notices and reporting its status.
 *
 * The InfoDesk class inherits from EventUnit and Observer, allowing it to be part of the event's unit structure,
 * receive notifications about various events or changes in the system, and report its own status accordingly.
 */
class InfoDesk : public EventUnit, public Observer
{
    private:
        /// @brief Indicates whether staff are currently available at the information desk.
        bool staffAvailable;
    public:
        /**
         * @brief Constructs a new InfoDesk instance.
         * @param deskName The name of the information desk, used for identification and reporting.
         * @param visitorCapacity The maximum number of visitors allowed at this desk.
         */
        InfoDesk(const std::string& deskName, int visitorCapacity);
        /// @brief Opens the information desk, making it available for use.
        void open() override;
        /// @brief Closes the information desk, preventing further use.
        void close() override;
        /// @brief Reports the current status of the information desk.
        void reportStatus() const override;
        /// @brief Updates the information desk based on the received notice.
        /// @param notice The notice received by the information desk.
        void update(const Notice& notice) override;
        /// @brief Destructor for the InfoDesk class.
        virtual ~InfoDesk();
};

#endif