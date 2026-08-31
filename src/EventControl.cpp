#include "EventControl.h"
#include "Notice.h"

EventControl::EventControl() {}

void EventControl::issueNotice(const Notice& notice) {
    notify(notice);
}

EventControl::~EventControl() {}