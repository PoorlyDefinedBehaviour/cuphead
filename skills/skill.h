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
    bool hasLeftScreen();
    bool isOwnedByPlayer();
    Vector2D getDimensions();
    int getDamage() const;

    Vector2D position;
    Animation animation;

protected:
    int damage = GameConstants::skills::DEFAULT_DAMAGE;
    Vector2D velocity;
    bool ownedByPlayer = false;
    float velocityIncrementer = 0.03;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
};

