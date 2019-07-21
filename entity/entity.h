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

    auto draw() -> void;
    auto flipAnimation(const bool shouldFlip) -> void;
    auto play(const std::string& animatioName, const bool force = false) -> void;
    auto move(const std::string& direction) -> void;
    auto receiveDamage(const int amount) -> void;

    auto update() -> void;
    auto isOnGround() -> bool;
    auto isAnimationFlipped() const -> bool;
    auto isDead() -> bool;

    auto setHealth(const int amount) -> void;
    auto getHealth() -> int;
    auto getDimensions() -> Vector2D;
    auto getCurrentAnimation() -> Animation&;


private:
    int health = 3;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
};

