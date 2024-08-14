#ifndef EVENT_QUEUE_H
#define EVENT_QUEUE_H

#include "Event.h"
#include <queue>
#include <mutex>
#include <condition_variable>

class EventQueue {
public:
    void push(const Event& event);
    Event pop();
    bool empty() const;

private:
    std::queue<Event> events;
    mutable std::mutex mtx;
    std::condition_variable cv;
};

#endif // EVENT_QUEUE_H