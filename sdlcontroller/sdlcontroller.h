#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <windows.h>
#include <string>
#include <map>

class SDLController
{
public:
    SDLController() = delete;

    static auto init(const bool fullscreen) -> void;

    static auto setRendererColor(const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a = 0) -> void;

    static auto loadImage(const char* file) -> SDL_Texture* ;
    static auto render(SDL_Texture* texture, SDL_Rect* destination, SDL_Rect* source = nullptr, const SDL_RendererFlip& flip = SDL_FLIP_NONE) -> void;
    static auto renderRectangle(const int width, const int height, const float x, const float y) -> void;

    static auto updateScreen() -> void;

    static auto playAudio(const std::string& audio, const int loops = 0, const int time = 0) -> void;
    static auto setVolume(const std::string& audio, const int volume) -> void;

    static auto exit() -> void;

private:
    static std::map<const std::string, Mix_Music*> songs;
    static std::map<const std::string, Mix_Chunk*> soundEffects;

    static SDL_Window* window;
    static SDL_Renderer* renderer;

    static auto loadMp3(const char* file) -> Mix_Music*;
    static auto loadWav(const char* file) -> Mix_Chunk*;
};

