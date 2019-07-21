#pragma once

#include "sdlcontroller/sdlcontroller.h"
#include "image/image.h"
#include <vector>
#include <SDL2/SDL.h>

class Animation
{
public:
    Animation();

    Animation(const std::vector<const char*>& images, const bool blocking = false, const int delay = 3);

    auto getNumOfFrames() const -> size_t;

    auto requestAnimationFrame() ->  SDL_Texture*;

    auto isLastFrame() -> bool;
    auto isBlocking() -> bool;

    auto setDelay(const int delay) -> void;

    auto getDimensions() -> Vector2D;

    int currentFrame = 0;

private:
    int timePassed = 0;
    int ticks = 0;
    int width;
    int height;
    int delay;
    std::vector<Image> frames;
    bool blocking;
};

