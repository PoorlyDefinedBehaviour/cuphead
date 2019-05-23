#include "skills/boomerang/boomerang.h"
#include "shared/constants.h"
#include "shared/animations.h"
#include "entity/entity.h"

Boomerang::Boomerang(Entity* entity)
{
    this->damage = GameConstants::skills::BOOMERANG_DAMAGE;
    this->position = {entity->position.x, entity->position.y + 180};

    int velocityRandomizer = rand() % 2;
    this->velocity = {-5, velocityRandomizer == 0 ? 5 : -5};
    this->velocityIncrementer = 0.1;
    this->animation = Animation(animations::projectiles::BOOMERANG_ANIMATION_FRAMES);
}

void Boomerang::update(){
    this->position = this->position.add(this->velocity);

    static float initialYPos = this->position.y;
    if(this->position.y > GameConstants::window::WINDOW_HEIGHT - this->getDimensions().y || this->position.y < 0)
        this->velocity.y *= -1;
}
