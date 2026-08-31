#include "ComponentUtils.h"
#include "EventComponent.h"
#include "EventGroup.h"
#include "Observer.h"
#include "Subject.h"

bool reassignComponent(EventComponent* unit, EventGroup* from, EventGroup* to)
{
    if (!unit || !from || !to || from == to) return false;

    // Step 1: detach from old owner without deleting. remove() returns
    // false if 'unit' wasn't actually owned by 'from', so we bail out
    // cleanly rather than risking double ownership / a later double-free.
    if (!from->remove(unit)) {
        return false;
    }

    // Step 2: if this unit is also an Observer, and its containing
    // groups happen to be Subjects (not every EventGroup is - only specific zones like CommunityZone/ExpoFloor/MainArea/IndieAlley mix in Subject)
    //, move its registration so it hears notices from
    // wherever it now physically lives.
    Observer* obs = dynamic_cast<Observer*>(unit);
    Subject* fromSubject = dynamic_cast<Subject*>(from);
    Subject* toSubject = dynamic_cast<Subject*>(to);

    if (obs) {
        if (fromSubject) fromSubject->detach(obs);
        if (toSubject) toSubject->attach(obs);
    }

    // Step 3: attach to new owner. From here 'to' is solely responsible
    // for eventually deleting 'unit'.
    to->add(unit);
    return true;
}
