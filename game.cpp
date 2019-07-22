#include "game.h"
#include "shared/animations.h"
#include "shared/constants.h"
#include "entity/entity.h"
#include "animation/animation.h"
#include "skills/skill.h"
#include "skills/seedmissile/seedmissile.h"
#include "skills/boomerang/boomerang.h"
#include "skills/venus/venus.h"
#include "skills/pollen/pollen.h"
#include "skills/ray/ray.h"
#include "events/eventemitter.h"
#include "collision/collision.h"
#include <SDL2/SDL_image.h>
#include <ctime>

std::unique_ptr<Entity> Game::player;
std::unique_ptr<Entity> Game::boss;
std::vector<TimeoutObject> Game::timeoutQueue;
std::vector<EventEmitter*> Game::EventEmitterInstances;
SDL_Event Game::event;
std::vector<Skill*> Game::skillList;

auto Game::init() -> void
{
    std::srand(std::time(nullptr));

    SDLController::init(false);
    SDLController::playAudio(GameConstants::sounds::MAIN_THEME, -1);
    SDLController::setVolume(GameConstants::sounds::MAIN_THEME, 30);

    this->BRAVO_IMAGE = SDLController::loadImage(GameConstants::assets::images::BRAVO_IMAGE);
    this->LIFE_DARK = SDLController::loadImage(GameConstants::assets::images::LIFE_DARK);
    this->LIFE_FILLED = SDLController::loadImage(GameConstants::assets::images::LIFE_FILLED);

    player = std::make_unique<Entity>(100, 0);

    player->setHealth(GameConstants::PLAYER_HEALTH);
    player->animations.emplace(animations::cuphead::PULLING_PANTS, Animation(animations::cuphead::PULLING_PANTS_ANIMATION_FRAMES));
    player->animations.emplace(animations::cuphead::IDLE, Animation(animations::cuphead::IDLE_ANIMATION_FRAMES, false, 5));
    player->animations.emplace(animations::cuphead::RUN, Animation(animations::cuphead::RUN_ANIMATION_FRAMES));
    player->animations.emplace(animations::cuphead::JUMP, Animation(animations::cuphead::JUMP_ANIMATION_FRAMES));
    player->animations.emplace(animations::cuphead::ATTACK, Animation(animations::cuphead::ATTACK_ANIMATION_FRAMES));
    player->animations.emplace(animations::cuphead::RUN_ATTACK, Animation(animations::cuphead::RUNNING_ATTACK_ANIMATION_FRAMES));
    player->animations.emplace(animations::cuphead::DEATH, Animation(animations::cuphead::DEATH_ANIMATION_FRAMES, true));


    boss =  std::make_unique<Entity>(GameConstants::window::WINDOW_WIDTH - 400, GameConstants::window::WINDOW_HEIGHT - 636);

    boss->setHealth(GameConstants::BOSS_HEALTH);
    boss->animations.emplace(animations::cagney::INTRO, Animation(animations::cagney::INTRO_ANIMATION_FRAMES));
    boss->animations.emplace(animations::cagney::IDLE, Animation(animations::cagney::IDLE_ANIMATION_FRAMES));
    boss->animations.emplace(animations::cagney::DEATH, Animation(animations::cagney::DEATH_ANIMATION_FRAMES));
    boss->animations.emplace(animations::cagney::CREATE_OBJECT, Animation(animations::cagney::CREATE_OBJECT_ANIMATION_FRAMES));
    boss->animations.emplace(animations::cagney::FIRING_SEEDS, Animation(animations::cagney::FIRING_SEEDS_ANIMATION_FRAMES));
    boss->animations.emplace(animations::projectiles::BLUE_MISSILE_SEED_LAUNCH, Animation(animations::projectiles::BLUE_MISSILE_SEED_LAUNCH_ANIMATION_FRAMES));


    boss->addEventListener("attack_over", []() -> void {
                               auto getRandomAnimation = []() -> std::string {

                                   const int skillToUse = rand() % 2;

                                   if(skillToUse == 0){
                                       addSkillToList(new Venus(&*player));
                                       return animations::cagney::CREATE_OBJECT;
                                   }

                                   return animations::cagney::FIRING_SEEDS;
                               };

                               auto createSkillForAnimation = [](const std::string& animation) -> void {
                                   if(animation == animations::cagney::FIRING_SEEDS){
                                       addSkillToList(new SeedMissile());
                                       SDLController::playAudio(GameConstants::sounds::cagney::CAGNEY_FIRING_SEEDS, 0, 1000);
                                       SDLController::setVolume(GameConstants::sounds::cagney::CAGNEY_FIRING_SEEDS, 20);
                                   }

                                   if(animation == animations::cagney::CREATE_OBJECT){
                                       int randomSkill = rand() % 2;
                                       if(randomSkill == 0){
                                           setTimeout(1000, []() -> void {
                                               addSkillToList(new Pollen(&*boss));
                                           });
                                       } else {
                                           setTimeout(1000, []() -> void {
                                               addSkillToList(new Boomerang(&*boss));
                                           });
                                       }
                                   }
                               };

                               const std::string animation = getRandomAnimation();
                               boss->play(animation);
                               createSkillForAnimation(animation);

                           }, true);
}

auto Game::run() -> void
{
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    Uint32 frameTime;

    SDL_Texture* landingImage = nullptr;
    int landing = rand() % 2;
    switch(landing){
    case 0: landingImage = SDLController::loadImage(GameConstants::assets::images::LANDING_ONE); break;
    case 1: landingImage = SDLController::loadImage(GameConstants::assets::images::LANDING_TWO); break;
    }

    SDLController::render(landingImage, nullptr);
    SDLController::updateScreen();
    SDL_Delay(2000);

    boss->play(animations::cagney::INTRO);
    SDLController::playAudio(GameConstants::sounds::cagney::CAGNEY_INTRO_YELL);
    SDLController::setVolume(GameConstants::sounds::cagney::CAGNEY_INTRO_YELL, 10);

    while(true)
    {
        frameStart = SDL_GetTicks();

        update();
        handleEvents();
        draw();
        destroyUsedSkills();

        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
    }
}

auto Game::update() -> void
{
    this->pollEvents();

    checkCollision();

    if(player->isDead()){
        SDLController::playAudio(GameConstants::sounds::cuphead::CUPHEAD_DEATH);
        SDLController::setVolume(GameConstants::sounds::cuphead::CUPHEAD_DEATH, 7);
        SDLController::playAudio(GameConstants::sounds::GAME_OVER);
        SDLController::setVolume(GameConstants::sounds::GAME_OVER, 10);
        player->play(animations::cuphead::DEATH, true);
        player->addEventListener("animationover", []() -> void {
                                     player->setHealth(1000);
                                     player->play(animations::cuphead::IDLE);
                                     setTimeout(1000, []() -> void {
                                         player->setHealth(GameConstants::PLAYER_HEALTH);
                                     });
                                 });
        restartGame();
    }

    if(player->getCurrentAnimation().isLastFrame()){
        player->emit("animationover");
    }

    player->update();

    boss->update();

    for(auto& skill : skillList)
    {
        skill->update();
    }

    bossController();

    if(!player->isOnGround())
    {
        player->velocity.y += GameConstants::WORLD_GRAVITY;
    }
    else {
        player->velocity.y = 0;
    }

    if(player->position.y + player->getDimensions().y > GameConstants::FLOOR_HEIGHT)
    {
        player->position.y = GameConstants::FLOOR_HEIGHT - player->getDimensions().y;
    }
}

auto Game::draw() -> void
{
    drawBackground();

    player->draw();

    boss->draw();

    for(const auto& skill : skillList)
    {
        skill->draw();
    }

    drawScenario();

    if(boss->isDead()){
        player->setHealth(9999);
        static int delayBetweenFrames = 10;
        static int timePassed = 0;
        static int currentRow = 0;
        static int currentColumn = 0;
        static SDL_Rect source;
        source.x = 1282 * currentColumn;
        source.y = 724 * currentRow;
        source.w = 1282;
        source.h = 724;

        SDLController::render(BRAVO_IMAGE, &source);
        if(timePassed >= delayBetweenFrames){
            ++currentColumn;
            if(currentColumn >= 3){
                currentColumn = 0;
                ++currentRow ;
            }
            timePassed = 0;
        }
        ++timePassed;
        if(currentRow >= 9){
            timePassed = 0;
            currentRow = 0;
            currentColumn = 0;
            restartGame();
        }
    }

    SDL_Rect lifeDest;
    lifeDest.x = 16;
    lifeDest.y = 16;
    lifeDest.w = 84;
    lifeDest.h = 75;

    for(int i=0; i<3; ++i){
        SDLController::render(this->LIFE_DARK, nullptr, &lifeDest);
        lifeDest.x += 86;
    }

    lifeDest.x = 16;

    if(player->getHealth() <= GameConstants::PLAYER_HEALTH){
        for(int i=0; i<player->getHealth(); ++i){
            SDLController::render(this->LIFE_FILLED, nullptr, &lifeDest);
            lifeDest.x += 86;
        }
    }
    SDLController::updateScreen();
}

auto Game::drawBackground() -> void
{
    static bool loaded = false;
    static SDL_Texture* background;

    if(!loaded)
    {
        background = SDLController::loadImage(GameConstants::assets::images::BACKGROUND);
        loaded = true;
    }

    SDL_Rect initialBackgroundDest;
    initialBackgroundDest.x = 0;
    initialBackgroundDest.y = 0;
    initialBackgroundDest.w = GameConstants::window::WINDOW_WIDTH;
    initialBackgroundDest.h = GameConstants::window::WINDOW_HEIGHT;

    SDLController::render(background, nullptr, &initialBackgroundDest, SDL_FLIP_NONE);
}

auto Game::drawScenario() -> void
{
    static bool loaded = false;
    static SDL_Texture* flowers;
    static SDL_Texture* grass;

    if(!loaded)
    {
        flowers = SDLController::loadImage(GameConstants::assets::images::FLOWERS);
        grass = SDLController::loadImage(GameConstants::assets::images::GRASS);
        loaded = true;
    }

    SDL_Rect flowersDest;
    flowersDest.x = -50;
    flowersDest.y = GameConstants::window::WINDOW_HEIGHT - 230;
    flowersDest.w = 1536;
    flowersDest.h = 352;

    SDL_Rect grassDest;
    grassDest.x = GameConstants::window::WINDOW_WIDTH - 400;
    grassDest.y = GameConstants::window::WINDOW_HEIGHT - 350;
    grassDest.w = 512;
    grassDest.h = 351;

    SDLController::render(grass, nullptr, &grassDest, SDL_FLIP_NONE);
    SDLController::render(flowers, nullptr, &flowersDest, SDL_FLIP_NONE);
}

auto Game::handleEvents() -> void
{
    SDL_PumpEvents();
    SDL_PollEvent(&event);

    Uint8* keysArray = const_cast<Uint8*>(SDL_GetKeyboardState(nullptr));

    if(!player->isDead()){
        if(keysArray[SDL_SCANCODE_SPACE])
        {
            player->play(animations::cuphead::ATTACK);
            static int delay = 0;
            if(delay <= 0){
                SDLController::playAudio(GameConstants::sounds::cuphead::CUPHEAD_ATTACK, 0, 100);
                SDLController::setVolume(GameConstants::sounds::cuphead::CUPHEAD_ATTACK, 30);
                addSkillToList(new Ray(&*player));
                delay += 10;
            }
            --delay;
        }

        if(keysArray[SDL_SCANCODE_W])
            if(player->isOnGround()){
                player->move("jump");
                SDLController::playAudio(GameConstants::sounds::cuphead::CUPHEAD_JUMP);
                SDLController::setVolume(GameConstants::sounds::cuphead::CUPHEAD_JUMP, 30);
            }

        if(keysArray[SDL_SCANCODE_D]){
            player->play(animations::cuphead::RUN);
            player->move("right");
            player->flipAnimation(false);
        }

        if(keysArray[SDL_SCANCODE_A]){
            player->play(animations::cuphead::RUN);
            player->move("left");
            player->flipAnimation(true);
        }

        if(keysArray[SDL_SCANCODE_F1]){
            player->play(animations::cuphead::PULLING_PANTS);
        }

        if(keysArray[SDL_SCANCODE_D] and keysArray[SDL_SCANCODE_SPACE]){
            player->play(animations::cuphead::RUN_ATTACK);
            static int delay = 0;
            if(delay <= 0){
                addSkillToList(new Ray(&*player));
                delay += 10;
            }
            --delay;
        }

        if(keysArray[SDL_SCANCODE_A] and keysArray[SDL_SCANCODE_SPACE]){
            player->play(animations::cuphead::RUN_ATTACK);
            player->flipAnimation(true);
            static int delay = 0;
            if(delay <= 0){
                addSkillToList(new Ray(&*player));
                delay += 10;
            }
            --delay;
        }

        if(!keysArray[SDL_SCANCODE_W] and !keysArray[SDL_SCANCODE_A] and
                !keysArray[SDL_SCANCODE_D] and
                !keysArray[SDL_SCANCODE_SPACE] and !keysArray[SDL_SCANCODE_F1] and
                !keysArray[SDL_SCANCODE_F2])
        {
            player->play(animations::cuphead::IDLE);
        }

        if(!player->isOnGround())
            player->play(animations::cuphead::JUMP);
    }

    if(event.type == SDL_QUIT or keysArray[SDL_SCANCODE_ESCAPE])
    {
        SDLController::exit();
    }
}

auto Game::addSkillToList(Skill* skill) -> void
{
    skillList.emplace_back(std::move(skill));
}

auto Game::destroyUsedSkills() -> void
{
    for(size_t i=0; i<skillList.size(); ++i)
    {
        if(skillList[i]->hasLeftScreen())
        {
            destroySkill(i);
        }
    }
}

auto Game::destroySkill(const size_t& index) -> void
{
    delete skillList[index];
    skillList.erase(skillList.begin() + index);
}

auto Game::checkCollision() -> void
{
    for(size_t i=0; i<skillList.size(); ++i){
        if(skillList[i]->isOwnedByPlayer() && Collision::AABB(&*boss, &*skillList[i])){
            boss->receiveDamage(skillList[i]->getDamage());
            destroySkill(i);
        }
        else if(!skillList[i]->isOwnedByPlayer() && Collision::AABB(&*player, &*skillList[i])){
            player->receiveDamage(skillList[i]->getDamage());
            destroySkill(i);
        }
    }

    if(Collision::AABB(&*player, &*boss)){
        player->receiveDamage(1);
    }

    for(size_t i=0; i<skillList.size(); ++i){
        for(size_t j=0; j<skillList.size(); ++j){
            if(skillList[i]->isOwnedByPlayer() && !skillList[j]->isOwnedByPlayer() && Collision::AABB(&*skillList[i], &*skillList[j])){
                destroySkill(j);
            }
        }
    }
}

auto Game::bossController() -> void
{
    if(boss->currentAnimation == animations::cagney::INTRO && boss->getCurrentAnimation().isLastFrame())
        boss->play(animations::cagney::IDLE);

    if(boss->isDead())
        boss->play(animations::cagney::DEATH);
    else
        if(boss->getCurrentAnimation().isLastFrame())
            boss->emit("attack_over");
}

auto Game::subscribeEventEmitter(EventEmitter* eventEmitter) -> void
{
    EventEmitterInstances.emplace_back(std::move(eventEmitter));
}

auto Game::pollEvents() -> void
{
    for(const auto& eventEmitter : EventEmitterInstances) {
        eventEmitter->pollEvents();
    }

    for(auto& timeout : timeoutQueue){
        if(!timeout.done and SDL_GetTicks() - timeout.startTime > timeout.ms){
            timeout.func();
            timeout.done = true;
        }
    }
}

auto Game::setTimeout(const unsigned int ms, void(*func)()) -> void
{
    timeoutQueue.push_back({SDL_GetTicks(), ms, func, false});
}

auto Game::restartGame() -> void
{
    skillList.clear();
    timeoutQueue.clear();
    boss->setHealth(GameConstants::BOSS_HEALTH);
    player->setHealth(GameConstants::PLAYER_HEALTH);
    player->position = {100, 100};
    boss->play(animations::cagney::INTRO, true);
    SDLController::playAudio(GameConstants::sounds::cagney::CAGNEY_INTRO_YELL);
    SDLController::setVolume(GameConstants::sounds::cagney::CAGNEY_INTRO_YELL, 10);
}
