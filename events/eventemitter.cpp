#include "events/eventemitter.h"
#include "game.h"

EventEmitter::EventEmitter(){
    Game::subscribeEventEmitter(this);
}

void EventEmitter::emit(const std::string &eventName)
{
    emittedEvents.push_back(eventName);
}

void EventEmitter::addEventListener(const std::string &event, void (*func)(), const bool &permanent)
{
    eventReactions.push_back({event, permanent, func});
    pollEvents();
}

void EventEmitter::pollEvents()
{
    for(int i=0; i<eventReactions.size(); ++i){
        for(int j=0; j<emittedEvents.size(); ++j){
            if(eventReactions[i].eventToActOn == emittedEvents[j]){
                eventReactions[i].func();
                if(!eventReactions[i].isPermanent)
                    eventReactions.erase(eventReactions.begin() + i);
            }
        }
    }
    emittedEvents.clear();
}

