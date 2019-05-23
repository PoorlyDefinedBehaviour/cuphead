#include "shared/animations.h"
#include "skills/ray/ray.h"
#include "entity/entity.h"
#include "animation/animation.h"
#include "image/image.h"

Ray::Ray(Entity* entity)
{
    position = {entity->isAnimationFlipped() ? entity->position.x - 60 : entity->position.x + entity->getDimensions().x + 20 , entity->position.y + 55};
    velocity = {entity->isAnimationFlipped() ? -5 : 5, 0};
    flip = entity->isAnimationFlipped() ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
    velocityIncrementer = 0.1;
    animation = Animation(animations::projectiles::RAY_ANIMATION_FRAMES);
    damage = GameConstants::skills::RAY_DAMAGE;
    this->ownedByPlayer = true;
}
