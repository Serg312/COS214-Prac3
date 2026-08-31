#ifndef PRACTICEBOOTH_H
#define PRACTICEBOOTH_H

#include "EventUnit.h"
#include "Observer.h"

/**
 * @brief Allows use of the notice classes without including the entire Notice.h header, reducing compilation dependencies.
 */
class Notice;

/**
 * @brief Represents a practice booth within the event, capable of receiving notices and reporting its status.
 *
 * The PracticeBooth class inherits from EventUnit and Observer, allowing it to be part of the event's unit structure,
 * receive notifications about various events or changes in the system, and report its own status accordingly.
 */
class PracticeBooth : public EventUnit, public Observer
{
    private:
        /// @brief Indicates whether the practice booth is currently occupied.
        bool occupied;
    public:
        /**
         * @brief Constructs a new PracticeBooth instance.
         * @param boothName The name of the practice booth, used for identification and reporting.
         * @param playerCapacity The maximum number of players allowed in this practice booth.
         */
        PracticeBooth(const std::string& boothName, int playerCapacity);
        /// @brief Opens the practice booth, allowing players to enter.
        void open() override;
        /// @brief Closes the practice booth, preventing further players from entering.
        void close() override;
        /// @brief Reports the current status of the practice booth, including occupancy and capacity.
        void reportStatus() const override;
        /// @brief Updates the practice booth based on the received notice.
        /// @param notice The notice received by the practice booth.
        void update(const Notice& notice) override;
        /// @brief Destructor for the PracticeBooth class.
        virtual ~PracticeBooth();
};

#endif  