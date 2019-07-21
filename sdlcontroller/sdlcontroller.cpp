#include "sdlcontroller/sdlcontroller.h"
#include "shared/constants.h"
#include <SDL2/SDL_mixer.h>

SDL_Window* SDLController::window;
SDL_Renderer* SDLController::renderer;
std::map<const std::string, Mix_Music*> SDLController::songs;
std::map<const std::string, Mix_Chunk*> SDLController::soundEffects;

auto SDLController::init(const bool fullscreen) -> void
{
    ShowWindow(GetConsoleWindow(), SW_HIDE);

    Uint32 flags = SDL_WINDOW_OPENGL;
    if(fullscreen){
        flags = SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN;
    }
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);

    IMG_Init(IMG_INIT_JPG |
             IMG_INIT_PNG |
             IMG_INIT_TIF);

    window = SDL_CreateWindow(GameConstants::window::WINDOW_TITLE,
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              GameConstants::window::WINDOW_WIDTH,
                              GameConstants::window::WINDOW_HEIGHT,
                              flags);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(renderer, 0xff, 0xb4, 0xff, 0xff);

    SDL_Surface* windowIcon = SDL_LoadBMP(GameConstants::assets::images::FAVICON);
    SDL_SetWindowIcon(window, windowIcon);
    SDL_FreeSurface(windowIcon);

    songs.emplace(GameConstants::sounds::MAIN_THEME, loadMp3(GameConstants::assets::audio::MAIN_THEME));
    soundEffects.emplace(GameConstants::sounds::cuphead::CUPHEAD_ATTACK, loadWav(GameConstants::assets::audio::CUPHEAD_ATTACK));
    soundEffects.emplace(GameConstants::sounds::cuphead::CUPHEAD_DEATH, loadWav(GameConstants::assets::audio::CUPHEAD_DEATH));
    soundEffects.emplace(GameConstants::sounds::cuphead::CUPHEAD_JUMP, loadWav(GameConstants::assets::audio::CUPHEAD_JUMP));
    soundEffects.emplace(GameConstants::sounds::cagney::CAGNEY_FIRING_SEEDS, loadWav(GameConstants::assets::audio::CAGNEY_FIRING_SEEDS));
    soundEffects.emplace(GameConstants::sounds::cagney::CAGNEY_INTRO_YELL, loadWav(GameConstants::assets::audio::CAGNEY_INTRO_YELL));
    soundEffects.emplace(GameConstants::sounds::PLAYER_HIT, loadWav(GameConstants::assets::audio::PLAYER_HIT));
    soundEffects.emplace(GameConstants::sounds::GAME_OVER, loadWav(GameConstants::assets::audio::GAME_OVER));
}

auto SDLController::loadImage(const char* file) -> SDL_Texture*
{
    SDL_Surface* tempImage = IMG_Load(file);
    SDL_Surface* optimizedImage = SDL_ConvertSurface(tempImage, tempImage->format, 0);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, optimizedImage);

    SDL_FreeSurface(tempImage);
    SDL_FreeSurface(optimizedImage);

    return texture;
}

auto SDLController::loadMp3(const char *file) -> Mix_Music*
{
    return Mix_LoadMUS(file);
}

auto SDLController::loadWav(const char *file) -> Mix_Chunk*
{
    return Mix_LoadWAV(file);
}

auto SDLController::playAudio(const std::string& audio, const int loops, const int time) -> void
{
    auto song = songs[audio];

    if(song) {
        Mix_PlayMusic(song, loops);
    }
    else {
        Mix_PlayChannelTimed(-1, soundEffects[audio], loops, time);
    }
}

auto SDLController::setVolume(const std::string& audio, const int volume) -> void
{
    auto song = songs[audio];

    if(song) {
        Mix_VolumeMusic(volume);
    }
    else {
        Mix_VolumeChunk(soundEffects[audio], volume);
    }
}

auto SDLController::setRendererColor(const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a) -> void
{
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

auto SDLController::render(SDL_Texture* texture, SDL_Rect* source, SDL_Rect* destination, const SDL_RendererFlip& flip) -> void
{
    if(!source || source->w < 0 || source->h < 0)
    {
        SDL_RenderCopyEx(renderer, texture, nullptr, destination, NULL, nullptr, flip);
    } else {
        SDL_RenderCopyEx(renderer, texture, source, destination, NULL, nullptr, flip);
    }
}

auto SDLController::renderRectangle(const int width, const int height, const float x, const float y) -> void
{
    SDL_Rect rectangle;
    rectangle.x = x;
    rectangle.y = y;
    rectangle.w = width;
    rectangle.h = height;

    SDL_RenderFillRect(renderer, &rectangle);
}

auto SDLController::updateScreen() -> void
{
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
}

auto SDLController::exit() -> void
{
    Mix_CloseAudio();
    Mix_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
    std::exit(EXIT_SUCCESS);
}
