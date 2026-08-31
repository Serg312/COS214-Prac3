#ifndef INDIEBOOTH_H
#define INDIEBOOTH_H

#include "EventUnit.h"
#include "Observer.h"

/**
 * @brief Allows use of the notice classes without including the entire Notice.h header, reducing compilation dependencies.
 */
class Notice;

/**
 * @brief Represents an indie booth within the event, capable of receiving notices and reporting its status.
 *
 * The IndieBooth class inherits from EventUnit and Observer, allowing it to be part of the event's unit structure,
 * receive notifications about various events or changes in the system, and report its own status accordingly.
 */
class IndieBooth : public EventUnit, public Observer
{
    private:
        /// @brief Indicates whether a developer is present at the indie booth.
        bool developerPresent;
    public:
        /**
         * @brief Constructs a new IndieBooth instance.
         * @param boothName The name of the indie booth, used for identification and reporting.
         * @param visitorCapacity The maximum number of visitors allowed at this booth.
         */
        IndieBooth(const std::string& boothName, int visitorCapacity);
        /// @brief Opens the indie booth, making it available for use.
        void open() override;
        /// @brief Closes the indie booth, preventing further use.
        void close() override;
        /// @brief Reports the current status of the indie booth.
        void reportStatus() const override;
        /// @brief Updates the indie booth based on the received notice.
        /// @param notice The notice received by the indie booth.
        void update(const Notice& notice) override;
        /// @brief Destructor for the IndieBooth class.
        virtual ~IndieBooth();
};

#endif