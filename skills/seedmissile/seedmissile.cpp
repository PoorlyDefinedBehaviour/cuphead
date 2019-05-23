#include "shared/constants.h"
#include "shared/animations.h"
#include "skills/seedmissile/seedmissile.h"

SeedMissile::SeedMissile()
{
    this->damage = GameConstants::skills::SEED_MISSILE_DAMAGE;
    this->position = {rand() % GameConstants::window::WINDOW_WIDTH - 400, -(rand() % 60) + 30};
    this->velocity = {0, 5};
    this->velocityIncrementer = 0.1;
    this->animation = Animation(animations::projectiles::SEED_MISSILE_ANIMATION_FRAMES);
}
