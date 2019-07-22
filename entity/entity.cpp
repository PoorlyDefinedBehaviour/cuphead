#include "entity.h"
#include "shared/constants.h"
#include "shared/animations.h"
#include "sdlcontroller/sdlcontroller.h"

Entity::Entity(const float& x, const float& y)
{
    position.x = x;
    position.y = y;
}

auto Entity::draw() -> void
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

void Entity::play(const std::string &animationName, const bool force)
{
    Animation* animation = &animations[currentAnimation];

    if (!animation->isBlocking() or animation->isLastFrame() or force){
        if(force) animations[animationName].currentFrame = 0;

        currentAnimation = animationName;
    }
}

auto Entity::update() -> void
{
    position = position.add(velocity);
}

auto Entity::flipAnimation(const bool shouldFlip) -> void
{
    if(shouldFlip) flip = SDL_FLIP_HORIZONTAL;
    else flip = SDL_FLIP_NONE;
}

auto Entity::isAnimationFlipped() const -> bool
{
    return flip != SDL_FLIP_NONE;
}

auto Entity::move(const std::string& direction) -> void
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

auto Entity::isOnGround() -> bool
{
    return static_cast<int>(position.y + getDimensions().y) >= GameConstants::FLOOR_HEIGHT;
}

auto Entity::getDimensions() -> Vector2D
{
    return this->animations[currentAnimation].getDimensions();
}

auto Entity::receiveDamage(const int amount) -> void
{
    if (this->health > 0) {
        SDLController::playAudio(GameConstants::sounds::PLAYER_HIT, 0, 100);
        SDLController::setVolume(GameConstants::sounds::PLAYER_HIT, 10);
        this->health -= amount;
    }
}

auto Entity::isDead() -> bool
{
    return this->health <= 0;
}

auto Entity::setHealth(const int amount) -> void
{
    this->health = amount;
}

auto Entity::getHealth() -> int
{
    return this->health;
}

auto Entity::getCurrentAnimation() -> Animation&
{
    return this->animations[this->currentAnimation];
}
