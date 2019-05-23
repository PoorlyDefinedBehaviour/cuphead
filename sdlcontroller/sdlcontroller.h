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
    static void init(const bool& fullscreen);
    static SDL_Texture* loadImage(const char* file);
    static void render(SDL_Texture* texture, SDL_Rect* destination, SDL_Rect* source = nullptr, const SDL_RendererFlip& flip = SDL_FLIP_NONE);
    static void renderRectangle(const int& width, const int& height, const float& x, const float& y);
    static void updateScreen();
    static void playAudio(const std::string& audio, const int& loops = 0, const int& time = 0);
    static void setVolume(const std::string audio, const int& volume);
    static void setRendererColor(const int& r, const int& g, const int& b, const int& a = 0);
    static void exit();

private:
    static std::map<const std::string, Mix_Music*> songs;
    static std::map<const std::string, Mix_Chunk*> soundEffects;
    static SDL_Window* window;
    static SDL_Renderer* renderer;
    static Mix_Music* loadMp3(const char* file);
    static Mix_Chunk* loadWav(const char* file);
};

