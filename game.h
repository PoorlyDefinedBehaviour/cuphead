#pragma once

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <vector>
#include "skills/skill.h"
#include "events/eventemitter.h"

class Entity;
class Skill;
class WorldObject;
class Vector2D;

struct TimeoutObject{
    const Uint32 startTime;
    int ms;
    void(*func)();
    bool done;
};

class Game
{
public:
    void init();
    [[ noreturn ]] void run();

    static void addSkillToList(Skill* skill);
    static void subscribeEventEmitter(EventEmitter* eventEmitter);

private:
    void update();
    void draw();
    void restartGame();
    void bossController();
    void drawBackground();
    void drawScenario();
    void handleEvents();
    void destroyUsedSkills();
    void destroySkill(const size_t& index);
    void checkCollision();
    void pollEvents();
    static void setTimeout(const int& ms, void(*func)());
    static std::vector<EventEmitter*> EventEmitterInstances;
    static Entity* player;
    static Entity* boss;
    static std::vector<Skill*> skillList;
    static std::vector<TimeoutObject> timeoutQueue;
    static SDL_Event event;
    SDL_Texture* BRAVO_IMAGE;
    SDL_Texture* LIFE_FILLED;
    SDL_Texture* LIFE_DARK;
};



