#include "EventQueue.h"

// Push a new event onto the queue
void EventQueue::push(const Event& event) {
    std::lock_guard<std::mutex> lock(mtx);
    events.push(event);
    cv.notify_one();
}

// Pop an event from the queue
Event EventQueue::pop() {
    std::unique_lock<std::mutex> lock(mtx);
    while (events.empty()) {
        cv.wait(lock);
    }
    Event event = events.front();
    events.pop();
    return event;
}

// Check if the queue is empty
bool EventQueue::empty() const {
    std::lock_guard<std::mutex> lock(mtx);
    return events.empty();
}