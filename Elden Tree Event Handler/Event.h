#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <chrono>

class Event {
public:
    Event(const std::string& god, const std::string& data);
    std::string getGodName() const;
    std::string getEventData() const;
    std::chrono::time_point<std::chrono::steady_clock> getTimestamp() const;

private:
    std::string godName;
    std::string eventData;
    std::chrono::time_point<std::chrono::steady_clock> timestamp;
};

#endif // EVENT_H