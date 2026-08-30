#include "ComponentUtils.h"
#include "EventComponent.h"
#include "EventGroup.h"
#include "Observer.h"

bool reassignComponent(EventComponent* unit, EventGroup* from, EventGroup* to)
{
    if (!unit || !from || !to || from == to) return false;

    // Step 1: detach from old owner without deleting (remove() only
    // unlinks — it never calls delete).
    if (!from->remove(unit))
    {
        return false; // unit wasn't actually owned by 'from'
    }

    // Step 2: if this unit is also an Observer of its containing group,
    // move its registration so it keeps hearing notices from wherever
    // it now physically lives, and stops hearing notices meant for its
    // old area.
    Observer* obs = dynamic_cast<Observer*>(unit);
    if (obs) {
        from->detach(obs);
        to->attach(obs);
    }

    // Step 3: attach to new owner. From here 'to' is solely responsible
    // for eventually deleting 'unit'.
    to->add(unit);
    return true;
}
