#include "entity.h"
#include "shared/constants.h"
#include "shared/animations.h"
#include "sdlcontroller/sdlcontroller.h"

Entity::Entity(const float& x, const float& y)
{
    position.x = x;
    position.y = y;
}

void Entity::draw()
{
    Animation* anim = &animations[currentAnimation];

    SDL_Rect dest;
    dest.x = position.x;
    dest.y = position.y;
    dest.w = anim->getDimensions().x;
    dest.h = anim->getDimensions().y;

    SDLController::render(anim->requestAnimationFrame(), nullptr, &dest, flip);


    if (currentAnimation == animations::cagney::FIRING_SEEDS && anim->currentFrame > 2 && anim->currentFrame < anim->getNumOfFrames() - 3) {
        auto* blueMissileAnim = &animations[animations::projectiles::BLUE_MISSILE_SEED_LAUNCH];
        SDL_Rect d;
        d.x = position.x + 120;
        d.y = position.y - 100;
        d.w = blueMissileAnim->getDimensions().x;
        d.h = blueMissileAnim->getDimensions().y;

        SDLController::render(blueMissileAnim->requestAnimationFrame(), nullptr, &d, SDL_FLIP_NONE);
    }
}

void Entity::play(const std::string &animationName, const bool& force)
{
    Animation* animation = &animations[currentAnimation];

    if (!animation->isBlocking() || animation->isLastFrame() || force){
        if(force){
            animations[animationName].currentFrame = 0;
        }
        currentAnimation = animationName;
    }
}

void Entity::update()
{
    position = position.add(velocity);
}

void Entity::flipAnimation(const bool &shouldFlip)
{
    if(shouldFlip){
        flip = SDL_FLIP_HORIZONTAL;
    }
    else {
        flip = SDL_FLIP_NONE;
    }
}

bool Entity::isAnimationFlipped() const
{
    return flip != SDL_FLIP_NONE;
}

void Entity::move(const std::string& direction)
{
    if(direction == "right")
    {
        if(position.x + animations[currentAnimation].getDimensions().x < GameConstants::window::WINDOW_WIDTH)
            position.x += speed;
    }
    else if(direction == "left")
    {
        if(position.x > 0)
            position.x -= speed;
    }

    if(direction == "jump")
    {
        if(position.y > 0 && isOnGround())
        {
            velocity.y = -GameConstants::PLAYER_JUMP_HEIGHT;
            position.y -= speed;
        }
    }
}

bool Entity::isOnGround()
{
    return static_cast<int>(position.y + getDimensions().y) >= GameConstants::FLOOR_HEIGHT;
}

Vector2D Entity::getDimensions()
{
    return this->animations[currentAnimation].getDimensions();
}

void Entity::receiveDamage(const int &amount)
{
    if (this->health > 0) {
        SDLController::playAudio(GameConstants::sounds::PLAYER_HIT, 0, 100);
        SDLController::setVolume(GameConstants::sounds::PLAYER_HIT, 10);
        this->health -= amount;
    }
}

bool Entity::isDead()
{
    return this->health <= 0;
}

void Entity::setHealth(const int& amount)
{
    this->health = amount;
}

int Entity::getHealth()
{
    return this->health;
}

Animation& Entity::getCurrentAnimation(){
    return this->animations[this->currentAnimation];
}
