# NexusCon — EventFlow

COS214 Practical 3 — a reusable event-coordination engine built around the
Composite and Observer design patterns.

**Event concept:** NexusCon is a large-scale, three-day gaming convention
featuring competitive esports tournaments, a publisher/indie expo floor,
and community-based support services. Because tournaments run on live
schedules, expo booths run demo hardware continuously, and the event
must respond to real-time issues (technical faults, capacity overflows,
safety alerts), the venue needs both a nested spatial structure and a
notification structure so changes spread quickly only to the areas that
need to react.

## Team

| Name | Student Number |
|---|---|
| Sergio Ferreira | u25247418 |
| Rafael de Gouveia | u25054903 |
| Johannes van Rensburg u| 25407725 |

## Building

```bash
make all      # builds the eventflow executable using -std=c++11
make run      # builds and runs it
make clean    # removes build artefacts
```

## Documentation

```bash
make docs     # runs `doxygen Doxyfile`, outputs to docs/html/index.html
```

Open `docs/html/index.html` in a browser to view generated documentation.

## Architecture Overview

```
NexusCon (root)
|
+-- Tournament Hall
|     +-- Main Area
|     |     +-- Tournament Stage
|     |     +-- Caster Booth
|     +-- Practice Zone
|           +-- Practice Booth
|
+-- Expo Floor
|     +-- Publisher Row
|     |     +-- Booth
|     |     +-- Demo Kiosk
|     +-- Indie Alley
|           +-- Indie Booth
|
+-- Community Zone
      +-- Cosplay Meetup Point
      +-- Charging Station
      +-- Info Desk
      +-- First Aid Point
      +-- Queue Management Point
```

- **`EventComponent`** — abstract Composite interface: `open()`,
  `close()`, `reportStatus()`, `getCapacity()`, `getName()`.
- **`EventUnit`** (Leaf) — adds `capacity`/`isOpen` state. Concrete
  leaves: `TournamentStage`, `CasterBooth`, `PracticeBooth`, `Booth`,
  `DemoKiosk`, `IndieBooth`, `CosplayMeetupPoint`, `ChargingStation`,
  `InfoDesk`, `FirstAidPoint`, `QueueManagementPoint`. Each also
  implements `Observer` directly, reacting to notices through its own
  overridden `open()`/`close()` behaviour.
- **`EventGroup`** (Composite) — owns children via `add()`/`remove()`
  (the latter returns `bool`, confirming successful removal). The root
  `NexusCon` and every zone/sub-zone (`TournamentHall`, `MainArea`,
  `PracticeZone`, `ExpoFloor`, `PublisherRow`, `IndieAlley`,
  `CommunityZone`) extend it.
- **Dual roles**: every zone except plain `EventGroup` itself also
  inherits `Observer` and `Subject` — e.g. `ExpoFloor` observes
  `NexusCon`'s notices and is itself a Subject to `PublisherRow`/
  `IndieAlley`. Two distinct collaborations on the same object,
  intentional per the spec (see design rationale in the submitted PDF).
- **`Notice`** — base class for pushed notification state (message +
  severity, severity fixed per concrete subtype). Concrete types:
  `EvacuationNotice`, `CapacityWarning`, `TechnicalOutage`,
  `QueueOverflowAlert`, `ResumptionNotice`, `OpenNotice`.
- **`EventControl`** — top-level Subject; `issueNotice(const Notice&)`
  triggers the cascade starting at `NexusCon`.
- **`reassignComponent(EventComponent*, EventGroup*, EventGroup*)`** —
  free utility function (Task 4.2) that safely transfers both ownership
  (via `remove()`/`add()`) and, where applicable, Observer registration
  (via `detach()`/`attach()`, checked with `dynamic_cast` since not
  every `EventGroup` is a `Subject`) between two zones.

## Ownership & Memory

`EventGroup` owns its children by composition and deletes them in its
own destructor — deleting the root releases the entire owned subtree
exactly once. `Subject` never deletes its observers; observer lifetime
is managed entirely through the Composite ownership tree instead, which
avoids a double-free when a class is both an owned child and an
attached observer of its parent. Verified leak-free via valgrind.

## Git/GitHub Workflow

See the Task 7 reflection in the submitted PDF for details on how work
was divided and integrated across the team.
