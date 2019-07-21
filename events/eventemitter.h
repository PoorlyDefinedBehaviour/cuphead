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

    auto emit(const std::string& eventName) -> void;
    auto addEventListener(const std::string& event, void(*func)(), const bool permanent = false) -> void;

    auto pollEvents() -> void;

private:
    std::vector<std::string> emittedEvents;
    std::vector<EventObject> eventReactions;
};

