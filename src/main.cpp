#include "EventGroup.h"
#include "TournamentHall.h"
#include "TournamentStage.h"
#include "EventControl.h"
#include "Notice.h"
#include <iostream>

/**
 * @brief Minimal end-to-end demo of EventFlow: builds a small Composite
 * tree, wires up the Observer chain on top of it, and demonstrates
 * attach/detach/notify at runtime as required by rule 9.
 */
int main() 
{
    // --- Composite side: build a small nested tree ---
    EventGroup* nexusCon = new EventGroup("NexusCon");

    TournamentHall* tournamentHall = new TournamentHall("Tournament Hall");
    nexusCon->add(tournamentHall);

    TournamentStage* mainStage = new TournamentStage("Center Stage", 5000);
    TournamentStage* sideStage = new TournamentStage("Side Stage", 1000);
    tournamentHall->add(mainStage);
    tournamentHall->add(sideStage);

    // --- Observer side: wire up who notifies whom ---
    EventControl control("NexusCon Control");
    control.attach(tournamentHall);       // control notifies the hall
    tournamentHall->attach(mainStage);    // hall notifies both stages
    tournamentHall->attach(sideStage);

    std::cout << "\n--- Opening the event (Composite side) ---\n";
    nexusCon->open();

    std::cout << "\n--- Issuing an evacuation notice (Observer side) ---\n";
    EvacuationNotice evac;
    control.issueNotice(evac); // cascades: control -> hall -> both stages

    std::cout << "\n--- Detaching Side Stage at runtime ---\n";
    tournamentHall->detach(sideStage);

    std::cout << "\n--- Issuing a resumption notice (Side Stage should NOT react) ---\n";
    ResumptionNotice resume;
    control.issueNotice(resume); // only mainStage should react now

    std::cout << "\n--- Closing the event ---\n";
    nexusCon->close();

    std::cout << "\n--- Destroying the root: entire owned subtree released once ---\n";
    delete nexusCon; // deletes tournamentHall, which deletes mainStage and sideStage

    return 0;
}