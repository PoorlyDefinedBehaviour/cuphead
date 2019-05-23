#include "skill.h"
#include "shared/animations.h"
#include "sdlcontroller/sdlcontroller.h"
#include "shared/constants.h"
#include "skills/ray/ray.h"
#include "skills/seedmissile/seedmissile.h"
#include "skills/pollen/pollen.h"
#include "skills/boomerang/boomerang.h"

Skill::~Skill(){}

void Skill::draw()
{
    SDL_Rect dest;
    dest.x = position.x;
    dest.y = position.y;
    dest.w = animation.getDimensions().x;
    dest.h = animation.getDimensions().y;

    SDLController::render(animation.requestAnimationFrame(), nullptr, &dest, flip);
}

void Skill::update()
{
    position = position.add(velocity);
    velocity.x = velocity.x > 0 ? velocity.x + velocityIncrementer : velocity.x - velocityIncrementer;
}

bool Skill::hasLeftScreen()
{
    return this->position.x < - 100;
}

bool Skill::isOwnedByPlayer(){
    return this->ownedByPlayer;
}

Vector2D Skill::getDimensions(){
    return this->animation.getDimensions();
}

int Skill::getDamage() const
{
    return damage;
}



