#pragma once

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include "skills/skill.h"
#include "events/eventemitter.h"

#include <vector>
#include <memory>

class Entity;
class Skill;
class WorldObject;
class Vector2D;

struct TimeoutObject{
    const Uint32 startTime;
    unsigned int ms;
    void(*func)();
    bool done;
};

class Game
{
public:
    auto init() -> void;
    [[ noreturn ]] auto run() -> void;

    static auto addSkillToList(Skill* skill) -> void;
    static auto subscribeEventEmitter(EventEmitter* eventEmitter) -> void;

private:
    auto update() -> void;

    auto draw() -> void;
    auto drawBackground() -> void;
    auto drawScenario() -> void;

    auto restartGame() -> void;
    auto handleEvents() -> void;
    auto checkCollision() -> void;
    auto pollEvents() -> void;
    auto bossController() -> void;

    auto destroyUsedSkills() -> void;
    auto destroySkill(const size_t& index) -> void;

    static auto setTimeout(const unsigned int ms, void(*func)()) -> void;

    static std::unique_ptr<Entity> player;
    static std::unique_ptr<Entity> boss;

    static std::vector<Skill*> skillList;
    static std::vector<TimeoutObject> timeoutQueue;
    static std::vector<EventEmitter*> EventEmitterInstances;

    static SDL_Event event;

    SDL_Texture* BRAVO_IMAGE;
    SDL_Texture* LIFE_FILLED;
    SDL_Texture* LIFE_DARK;
};



