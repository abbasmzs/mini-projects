#ifndef ELDEN_TREE_H
#define ELDEN_TREE_H

#include "EventQueue.h"
#include "Event.h"
#include <unordered_map>
#include <string>
#include <memory>

class EldenTree {
public:
    EldenTree();
    void addEvent(const Event& event);
    void processEvents();
    void registerGod(const std::string& godName);
    void deregisterGod(const std::string& godName);

private:
    std::unordered_map<std::string, std::shared_ptr<EventQueue>> eventQueues;
};

#endif // ELDEN_TREE_H