#include "shared/animations.h"
#include "skills/pollen/pollen.h"
#include "entity/entity.h"
#include <cmath>

Pollen::Pollen(Entity* entity)
{
    this->damage = GameConstants::skills::POLLEN_DAMAGE;
    this->position = {entity->position.x, entity->position.y + 180};
    this->velocity = {-5, 5};
    this->velocityIncrementer = 0.1;
    this->animation = Animation(animations::projectiles::POLLEN_ANIMATION_FRAMES);
}

void Pollen::update()
{
    this->position = this->position.add(this->velocity);

    static float initialYPos = this->position.y;
    if(std::abs(initialYPos - this->position.y) < 5 || std::abs(initialYPos - this->position.y) > 15)
        this->velocity.y *= -1;
}
