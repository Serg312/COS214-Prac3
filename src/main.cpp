#include "EventGroup.h"
#include "TournamentStage.h"
#include "CasterBooth.h"
#include "Booth.h"
#include "DemoKiosk.h"
#include "ChargingStation.h"
#include "QueueManagementPoint.h"
#include <iostream>

/**
 * @brief Build a sample NexusCon event tree and demonstrate Composite
 * behaviour: uniform recursive operations across every level, and
 * destruction of the entire owned subtree from a single delete on the root.
 */
int main() {
    // --- Level 3 leaves under Tournament Hall -> Main Arena ---
    EventComponent* stage  = new TournamentStage("Center Stage", 5000);
    EventComponent* caster = new CasterBooth("Caster Booth A", 10);

    EventGroup* mainArena = new EventGroup("Main Arena");
    mainArena->add(stage);
    mainArena->add(caster);

    // --- Level 3 leaf under Tournament Hall -> Practice Zone ---
    EventComponent* practiceBooth = new Booth("Practice Sign-Up Booth", 50);

    EventGroup* practiceZone = new EventGroup("Practice Zone");
    practiceZone->add(practiceBooth);

    // --- Level 1 composite: Tournament Hall ---
    EventGroup* tournamentHall = new EventGroup("Tournament Hall");
    tournamentHall->add(mainArena);
    tournamentHall->add(practiceZone);

    // --- Level 3 leaves under Expo Floor -> Publisher Row ---
    EventComponent* publisherBooth = new Booth("Publisher Booth - GameCorp", 100);
    EventComponent* demoKiosk      = new DemoKiosk("Demo Kiosk 1", 20);

    EventGroup* publisherRow = new EventGroup("Publisher Row");
    publisherRow->add(publisherBooth);
    publisherRow->add(demoKiosk);

    // --- Level 3 leaf under Expo Floor -> Indie Alley ---
    EventComponent* indieBooth = new Booth("Indie Booth - PixelWorks", 40);

    EventGroup* indieAlley = new EventGroup("Indie Alley");
    indieAlley->add(indieBooth);

    // --- Level 1 composite: Expo Floor ---
    EventGroup* expoFloor = new EventGroup("Expo Floor");
    expoFloor->add(publisherRow);
    expoFloor->add(indieAlley);

    // --- Level 2 leaves directly under Community Zone ---
    EventComponent* charging   = new ChargingStation("Charging Station", 30);
    EventComponent* queuePoint = new QueueManagementPoint("Queue Point - Main Entrance", 200);

    // --- Level 1 composite: Community Zone ---
    EventGroup* communityZone = new EventGroup("Community Zone");
    communityZone->add(charging);
    communityZone->add(queuePoint);

    // --- Level 0 (root): NexusCon ---
    EventGroup* nexusCon = new EventGroup("NexusCon");
    nexusCon->add(tournamentHall);
    nexusCon->add(expoFloor);
    nexusCon->add(communityZone);

    std::cout << "\n--- Opening the entire event from the root ---\n";
    nexusCon->open();

    std::cout << "\n--- Reporting status recursively from the root ---\n";
    nexusCon->reportStatus();

    std::cout << "\n--- Total event capacity (recursive sum through 3 levels) ---\n";
    std::cout << "NexusCon total capacity: " << nexusCon->getCapacity() << std::endl;

    std::cout << "\n--- Closing the entire event from the root ---\n";
    nexusCon->close();

    std::cout << "\n--- Destroying the root: entire owned subtree released exactly once ---\n";
    delete nexusCon;

    std::cout << "\nAll memory released. Every EventComponent was deleted exactly once,\n"
              << "by the single EventGroup that owned it.\n";

    return 0;
}
