#include "EldenTree.h"

EldenTree::EldenTree() {}

void EldenTree::addEvent(const Event& event) {
    auto godName = event.getGodName();
    if (eventQueues.find(godName) == eventQueues.end()) {
        eventQueues[godName] = std::make_shared<EventQueue>();
    }
    eventQueues[godName]->push(event);
}

void EldenTree::processEvents() {
    for (auto& pair : eventQueues) {
        auto& queue = pair.second;
        while (!queue->empty()) {
            Event event = queue->pop();
            // Process event (you can customize this part)
        }
    }
}

void EldenTree::registerGod(const std::string& godName) {
    if (eventQueues.find(godName) == eventQueues.end()) {
        eventQueues[godName] = std::make_shared<EventQueue>();
    }
}

void EldenTree::deregisterGod(const std::string& godName) {
    eventQueues.erase(godName);
}


//#include "EldenTree.h"
//#include <iostream>
//
//EldenTree::EldenTree() {}
//
//void EldenTree::addEvent(const Event& event) {
//    auto godName = event.getGodName();
//    if (eventQueues.find(godName) == eventQueues.end()) {
//        eventQueues[godName] = std::make_shared<EventQueue>();
//    }
//    eventQueues[godName]->push(event);
//}
//
//void EldenTree::processEvents() {
//    for (auto& pair : eventQueues) {
//        auto& queue = pair.second;
//        while (!queue->empty()) {
//            Event event = queue->pop();
//            // Print event details to the console
//            std::cout << "Processing event for " << event.getGodName()
//                << ": " << event.getEventData()
//                << " at " << event.getTimestamp().time_since_epoch().count() << std::endl;
//        }
//    }
//}
//
//void EldenTree::registerGod(const std::string& godName) {
//    if (eventQueues.find(godName) == eventQueues.end()) {
//        eventQueues[godName] = std::make_shared<EventQueue>();
//    }
//}
//
//void EldenTree::deregisterGod(const std::string& godName) {
//    eventQueues.erase(godName);
//}