#pragma once

#include "util/vector2d/vector2d.h"
#include "shared/constants.h"
#include "animation/animation.h"
#include <string>
#include <SDL2/SDL.h>

class Ray;
class Entity;

class Skill
{
public:
    virtual ~Skill();

    virtual void update();
    virtual void draw();

    auto hasLeftScreen() -> bool;
    auto isOwnedByPlayer() -> bool;

    auto getDimensions() -> Vector2D;
    auto getDamage() const -> int;

    Vector2D position;
    Animation animation;

protected:
    int damage = GameConstants::skills::DEFAULT_DAMAGE;

    Vector2D velocity;
    float velocityIncrementer = 0.03;

    bool ownedByPlayer = false;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
};

