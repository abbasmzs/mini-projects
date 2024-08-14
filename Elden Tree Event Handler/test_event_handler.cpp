// tests/test_event_handler.cpp
#include <gtest/gtest.h>

#include "EldenTree.h"

TEST(EventTest, BasicEventTest) {
    Event event("Zeus", "Thunderstorm");
    EXPECT_EQ(event.getGodName(), "Zeus");
    EXPECT_EQ(event.getEventData(), "Thunderstorm");
}

TEST(EventQueueTest, BasicQueueTest) {
    EventQueue queue;
    Event event("Hera", "Blessing");
    queue.push(event);
    EXPECT_FALSE(queue.empty());
    Event poppedEvent = queue.pop();
    EXPECT_EQ(poppedEvent.getGodName(), "Hera");
    EXPECT_TRUE(queue.empty());
}

TEST(EldenTreeTest, AddAndProcessEventTest) {
    EldenTree eldenTree;
    eldenTree.registerGod("Ares");
    eldenTree.addEvent(Event("Ares", "War Cry"));

    // Normally, processEvents() would do more complex processing
    eldenTree.processEvents();  // You can add checks if processEvents() has side effects
}