#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>

class Observer;
class Notice;

class Subject {
protected:
    std::vector<Observer*> observers;

public:
    virtual ~Subject();
    virtual void attach(Observer* observer);
    virtual void detach(Observer* observer);
    virtual void notify(const Notice& notice);
};

#endif