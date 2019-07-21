#include "image/image.h"
#include "util/vector2d/vector2d.h"
#include "sdlcontroller/sdlcontroller.h"

Image::Image(const char* image)
{
    this->texture = SDLController::loadImage(image);
    SDL_QueryTexture(this->texture, nullptr, nullptr, &width, &height);
}

auto Image::get() -> SDL_Texture*
{
    return this->texture;
}

