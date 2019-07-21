#include "events/eventemitter.h"
#include "game.h"

EventEmitter::EventEmitter(){

    Game::subscribeEventEmitter(this);
}

auto EventEmitter::emit(const std::string &eventName) -> void
{
    emittedEvents.push_back(eventName);
}

auto EventEmitter::addEventListener(const std::string &event, void (*func)(), const bool permanent) -> void
{
    eventReactions.push_back({event, permanent, func});
    pollEvents();
}

auto EventEmitter::pollEvents() -> void
{
    for(size_t i=0; i<eventReactions.size(); ++i){
        for(size_t j=0; j<emittedEvents.size(); ++j){
            if(eventReactions[i].eventToActOn == emittedEvents[j]){
                eventReactions[i].func();
                if(!eventReactions[i].isPermanent)
                    eventReactions.erase(eventReactions.begin() + i);
            }
        }
    }
    emittedEvents.clear();
}

