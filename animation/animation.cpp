#include "animation.h"
#include "image/image.h"
#include "util/vector2d/vector2d.h"

Animation::Animation(){}

Animation::Animation(const std::vector<const char*>& images, const bool& blocking, const int& delay)
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

int Animation::getNumOfFrames() const
{
    return this->frames.size();
}

SDL_Texture* Animation::requestAnimationFrame()
{
    if(timePassed >= delay){
        ++this->currentFrame;
        timePassed = 0;
    }

    ++timePassed;
    if(this->currentFrame >= this->getNumOfFrames())
        this->currentFrame = 0;

    return (this->frames[this->currentFrame]).get();
}

bool Animation::isLastFrame()
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

bool Animation::isBlocking(){
    return this->blocking;
}

void Animation::setDelay(const int& delay)
{
    this->delay = delay;
}

Vector2D Animation::getDimensions()
{
    return { this->width, this->height };
}
