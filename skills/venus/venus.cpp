#include "skills/venus/venus.h"
#include "shared/constants.h"
#include "shared/animations.h"

#include "util/debug/print.h"

Venus::Venus(Entity* entity)
{
    this->animation = Animation(animations::projectiles::VENUS_FLYING_PLANT_ANIMATION_FRAMES);
    this->target = entity;
    this->damage = GameConstants::skills::VENUS_FLYING_PLANT_DAMAGE;
    this->velocity = {0, 0};
    int number = rand() % 3;
    switch(number){
    case 0:
        this->position = {rand() % GameConstants::window::WINDOW_WIDTH - 600, - 50};
        break;
    case 1:
        this->position = {-100, rand() % GameConstants::window::WINDOW_HEIGHT - 400};
        break;
    case 2:
        this->position = {rand() % GameConstants::window::WINDOW_WIDTH - 600, GameConstants::window::WINDOW_HEIGHT + 100};
        break;
    }
}

void Venus::update(){
    this->velocity = {this->target->position.x - this->position.x, this->target->position.y - this->position.y};
    this->velocity = {this->velocity.x * 0.01, this->velocity.y * 0.01};

    this->velocity.x += this.velocity > 0 ? 0.01 : -0.01;

    this->flip = this->velocity.x > 0 ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
    
    this->position = this->position.add(this->velocity);
}
