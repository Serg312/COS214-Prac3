#include <iostream>
#include <iomanip>

#include "EventControl.h"
#include "NexusCon.h"
#include "ExpoFloor.h"
#include "TournamentHall.h"
#include "PracticeZone.h"
#include "DemoKiosk.h"
#include "TournamentStage.h"
#include "CosplayMeetupPoint.h"
#include "FirstAidPoint.h"
#include "InfoDesk.h"
#include "PracticeBooth.h"
#include "QueueManagementPoint.h"
#include "IndieBooth.h"
#include "Notice.h"

// Helper function for visual section headers in console output
void printBanner(const std::string& title) 
{
    std::cout << "  " << title << "\n\n\n";
}

int main() 
{
    // STEP 1: Initialize Central Event Control (Top-Level Subject)
    printBanner("STEP 1: INITIALIZING CENTRAL EVENT CONTROL");
    EventControl eventControl = EventControl("NexusCon Control Center");

    // STEP 2: Build Venue Hierarchy (Composite Pattern)
    printBanner("STEP 2: BUILDING VENUE TREE (COMPOSITE PATTERN)");

    // Root node
    NexusCon* rootCon = new NexusCon("NexusCon Main Convention");

    // Sub-zone nodes (EventGroups)
    ExpoFloor* expoFloor       = new ExpoFloor("Hall A - Expo Floor");
    TournamentHall* arenaHall  = new TournamentHall("Hall B - Esports Arena");
    PracticeZone* practiceZone = new PracticeZone("Zone C - Practice & Indie Alley");

    // Leaf nodes (EventUnits)
    DemoKiosk* vrKiosk            = new DemoKiosk("VR Hardware Kiosk", 8);
    CosplayMeetupPoint* cosplay   = new CosplayMeetupPoint("Cosplay Photo Point", 50);
    FirstAidPoint* firstAid       = new FirstAidPoint("Medical Station Alpha", 10);
    InfoDesk* infoDesk            = new InfoDesk("Central Info Desk", 5);
    TournamentStage* mainStage    = new TournamentStage("Main Stage", 300);
    QueueManagementPoint* stageQ  = new QueueManagementPoint("Stage Entry Queue", 150);
    PracticeBooth* practiceBooth  = new PracticeBooth("Free-Play Booth 1", 4);
    IndieBooth* indieBooth        = new IndieBooth("Pixel Craft Indie Booth", 6);

    // Assemble Expo Floor
    expoFloor->add(vrKiosk);
    expoFloor->add(cosplay);
    expoFloor->add(firstAid);
    expoFloor->add(infoDesk);

    // Assemble Esports Arena
    arenaHall->add(mainStage);
    arenaHall->add(stageQ);

    // Assemble Practice Zone
    practiceZone->add(practiceBooth);
    practiceZone->add(indieBooth);

    // Attach sub-zones to root
    rootCon->add(expoFloor);
    rootCon->add(arenaHall);
    rootCon->add(practiceZone);

    std::cout << "[Setup] Composite tree successfully assembled.\n";

    // STEP 3: Wire Notification Hierarchy (Observer Pattern)
    printBanner("STEP 3: REGISTERING OBSERVERS (OBSERVER PATTERN)");

    // Central Controller -> Root Composite
    eventControl.attach(rootCon);

    // Root Composite -> Sub-zones
    rootCon->attach(expoFloor);
    rootCon->attach(arenaHall);
    rootCon->attach(practiceZone);

    // Sub-zones -> Respective Leaf Units
    expoFloor->attach(vrKiosk);
    expoFloor->attach(cosplay);
    expoFloor->attach(firstAid);
    expoFloor->attach(infoDesk);

    arenaHall->attach(mainStage);
    arenaHall->attach(stageQ);

    practiceZone->attach(practiceBooth);
    practiceZone->attach(indieBooth);

    std::cout << "[Setup] Observer notification paths configured.\n";

    // STEP 4: Initial System State & Recursive Capacity Check
    printBanner("STEP 4: SYSTEM BASELINE & RECURSIVE CAPACITY");

    std::cout << "Total Venue Capacity: " << rootCon->getCapacity() << " visitors\n\n";
    std::cout << "--- Initial Status Report ---\n";
    rootCon->reportStatus();

    // STEP 5: Scenario Simulations (Testing Task 3 & 4 Features)
    
    // Scenario 5.1: Opening Facility
    printBanner("SCENARIO 5.1: MORNING OPENING BROADCAST");
    OpenNotice openNotice("Facility is now OPEN to the public.");
    eventControl.issueNotice(openNotice);

    std::cout << "\n--- Status Post-Opening ---\n";
    rootCon->reportStatus();

    // Scenario 5.2: Technical Outage 
    // Triggers Feature 1: Dynamic Power Grid Throttling (DemoKiosk)
    // Triggers Feature 2: Esports Stream Sync Protocol (TournamentStage)
    printBanner("SCENARIO 5.2: TECHNICAL OUTAGE (POWER GRID & STREAM SYNC)");
    TechnicalOutage powerFailure("Grid Overload: High voltage failure detected in sector 2.");
    eventControl.issueNotice(powerFailure);

    std::cout << "\n--- Unit Status Verification (Throttling & Stream Sync) ---\n";
    vrKiosk->reportStatus();
    mainStage->reportStatus();

    // Scenario 5.3: Crowd Congestion
    // Triggers Feature 3: Cosplay Safety Priority Beacon (CosplayMeetupPoint)
    printBanner("SCENARIO 5.3: QUEUE OVERFLOW ALERT (SAFETY BEACON)");
    QueueOverflowAlert crowdSpill("Cosplay Plaza capacity nearing total threshold!");
    eventControl.issueNotice(crowdSpill);

    // Scenario 5.4: Emergency Evacuation
    printBanner("SCENARIO 5.4: EMERGENCY EVACUATION PROCEDURES");
    EvacuationNotice emergencyEvac("IMMEDIATE EVACUATION REQUIRED! SAFETY HAZARD DETECTED.");
    eventControl.issueNotice(emergencyEvac);

    std::cout << "\n--- Status Post-Evacuation ---\n";
    rootCon->reportStatus();

    // Scenario 5.5: Normal Resumption
    printBanner("SCENARIO 5.5: ALL-CLEAR & RESUMPTION");
    ResumptionNotice clearNotice("All clear issued. System returning to standard operational status.");
    eventControl.issueNotice(clearNotice);

    // STEP 6: Safe Teardown & Memory Cleanup
    printBanner("STEP 6: TEARDOWN & MEMORY DEALLOCATION");

    // Detach Root from EventControl central subject
    eventControl.detach(rootCon);

    // Deleting rootCon triggers recursive destruction of all sub-groups and leaf units
    delete rootCon;
    rootCon = nullptr;

    std::cout << "[Teardown] Memory tree successfully freed.\n";

    return 0;
}