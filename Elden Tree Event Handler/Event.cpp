#include "Event.h"

// Constructor
Event::Event(const std::string& god, const std::string& data)
    : godName(god), eventData(data), timestamp(std::chrono::steady_clock::now()) {}

// Get the name of the god associated with the event
std::string Event::getGodName() const {
    return godName;
}

// Get the data associated with the event
std::string Event::getEventData() const {
    return eventData;
}

// Get the timestamp when the event was created
std::chrono::time_point<std::chrono::steady_clock> Event::getTimestamp() const {
    return timestamp;
}