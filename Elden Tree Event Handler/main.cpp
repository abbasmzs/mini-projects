#include "EldenTree.h"
#include <iostream>

int main() {
    EldenTree eldenTree;

    eldenTree.registerGod("Zeus");
    eldenTree.registerGod("Hera");

    eldenTree.addEvent(Event("Zeus", "Thunderstorm"));
    eldenTree.addEvent(Event("Hera", "Blessing"));

    eldenTree.processEvents();

    eldenTree.deregisterGod("Zeus");

    return 0;
}