#pragma once
#include <string>
#include <vector>

struct EventObject{
    std::string eventToActOn;
    bool isPermanent;
    void(*func)();
};

class EventEmitter
{
public:
    EventEmitter();
    void emit(const std::string& eventName);
    void addEventListener(const std::string& event, void(*func)(), const bool& permanent = false);
    void pollEvents();

private:
    std::vector<std::string> emittedEvents;
    std::vector<EventObject> eventReactions;
};

