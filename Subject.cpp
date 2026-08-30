#include "Subject.h"
#include "Observer.h"
#include "Notice.h"
#include <algorithm>

Subject::~Subject() {
    // Subject does not own observers; clear pointers without deleting them
    observers.clear();
}

void Subject::attach(Observer* observer) {
    if (!observer) return;
    auto it = std::find(observers.begin(), observers.end(), observer);
    if (it == observers.end()) {
        observers.push_back(observer);
    }
}

void Subject::detach(Observer* observer) {
    if (!observer) return;
    auto it = std::find(observers.begin(), observers.end(), observer);
    if (it != observers.end()) {
        observers.erase(it);
    }
}

void Subject::notify(const Notice& notice) {
    for (Observer* obs : observers) {
        if (obs) {
            obs->update(notice);
        }
    }
}