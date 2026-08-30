#ifndef OBSERVER_H
#define OBSERVER_H

class Notice;

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(const Notice& notice) = 0;
};

#endif