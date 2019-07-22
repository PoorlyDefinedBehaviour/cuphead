#include "animation.h"
#include "image/image.h"
#include "util/vector2d/vector2d.h"

Animation::Animation(){}

Animation::Animation(const std::vector<const char*>& images, const bool blocking, const int delay)
{
    for(const auto& image : images){
        frames.push_back(Image(image));
    }

    this->delay = delay;
    this->blocking = blocking;

    int totalWidth = 0, totalHeight = 0;
    for(auto& frame : this->frames)
    {
        totalWidth += frame.width;
        totalHeight += frame.height;
    }

    this->width = totalWidth / this->frames.size();
    this->height = totalHeight / this->frames.size();
}

auto Animation::getNumOfFrames() const -> size_t
{
    return this->frames.size();
}

auto Animation::requestAnimationFrame() -> SDL_Texture*
{
    if(++timePassed >= delay){
        ++this->currentFrame;
        timePassed = 0;
    }

    if(this->currentFrame >= this->getNumOfFrames())
        this->currentFrame = 0;

    return (this->frames[this->currentFrame]).get();
}

auto Animation::isLastFrame() -> bool
{
    ++this->ticks;

    if(this->ticks == this->delay && this->currentFrame == this->frames.size() - 1){
        this->ticks = 0;
        return true;
    }

    if(this->ticks == this->delay){
        this->ticks = 0;
    }

    return false;
}

auto Animation::isBlocking() -> bool
{
    return this->blocking;
}

auto Animation::setDelay(const int delay) -> void
{
    this->delay = delay;
}

auto Animation::getDimensions() -> Vector2D
{
    return { this->width, this->height };
}
