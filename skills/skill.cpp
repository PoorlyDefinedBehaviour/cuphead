#include "skill.h"
#include "shared/animations.h"
#include "sdlcontroller/sdlcontroller.h"
#include "shared/constants.h"
#include "skills/ray/ray.h"
#include "skills/seedmissile/seedmissile.h"
#include "skills/pollen/pollen.h"
#include "skills/boomerang/boomerang.h"

Skill::~Skill(){}

auto Skill::draw() -> void
{
    SDL_Rect dest;
    dest.x = position.x;
    dest.y = position.y;
    dest.w = animation.getDimensions().x;
    dest.h = animation.getDimensions().y;

    SDLController::render(animation.requestAnimationFrame(), nullptr, &dest, flip);
}

auto Skill::update() -> void
{
    position = position.add(velocity);
    velocity.x = velocity.x > 0 ? velocity.x + velocityIncrementer : velocity.x - velocityIncrementer;
}

auto Skill::hasLeftScreen() -> bool
{
    return this->position.x < - 100;
}

auto Skill::isOwnedByPlayer() -> bool
{
    return this->ownedByPlayer;
}

auto Skill::getDimensions() -> Vector2D
{
    return this->animation.getDimensions();
}

auto Skill::getDamage() const -> int
{
    return damage;
}



