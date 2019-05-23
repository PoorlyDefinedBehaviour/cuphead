#pragma once
#include <SDL2/SDL.h>

class Vector2D;

class Image
{
public:
    Image(const char* image);
    SDL_Texture* get();
    int width;
    int height;
private:
    SDL_Texture* texture;
};

