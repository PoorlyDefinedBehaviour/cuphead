#pragma once

#include "animation/animation.h"
#include "util/vector2d/vector2d.h"
#include "events/eventemitter.h"
#include <SDL2/SDL.h>
#include <map>

class Entity : public EventEmitter
{
public:
    Entity(const float& x, const float& y);

    virtual ~Entity(){}

    int speed = 5;

    Vector2D velocity;

    Vector2D position;

    std::map<std::string, Animation> animations;

    std::string currentAnimation = "idle";
    std::string currentSkill = "ray";

    void draw();
    void flipAnimation(const bool& shouldFlip);
    bool isAnimationFlipped() const;
    void play(const std::string& animatioName, const bool& force = false);
    void move(const std::string& direction);
    void update();
    bool isOnGround();
    Vector2D getDimensions();
    void receiveDamage(const int& amount);
    void setHealth(const int& amount);
    int getHealth();
    Animation& getCurrentAnimation();
    bool isDead();

private:
    int health = 3;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
};

