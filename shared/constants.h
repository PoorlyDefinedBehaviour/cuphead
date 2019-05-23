#pragma once
#include <string>

namespace GameConstants {

namespace window {
static const char* WINDOW_TITLE = "Cuphead";
static const int WINDOW_WIDTH = 1280;
static const int WINDOW_HEIGHT = 720;
}

static const float WORLD_GRAVITY = 0.37;

static const int BOSS_HEALTH = 500;
static const int PLAYER_HEALTH = 3;

static const int FLOOR_HEIGHT = window::WINDOW_HEIGHT - 180;

static const int PLAYER_JUMP_HEIGHT = 10;

namespace skills {
static const int DEFAULT_DAMAGE = 1;
static const int POLLEN_DAMAGE = 1;
static const int RAY_DAMAGE = 1;
static const int BOOMERANG_DAMAGE = 1;
static const int SEED_MISSILE_DAMAGE = 1;
static const int ACORN_DAMAGE = 1;
static const int VENUS_FLYING_PLANT_DAMAGE = 1;
}

namespace sounds {
static const std::string MAIN_THEME = "ost_fury";
static const std::string PLAYER_HIT = "player_hit";
static const std::string GAME_OVER = "game_over";

namespace cuphead {
static const std::string CUPHEAD_ATTACK = "cuphead_attack";
static const std::string CUPHEAD_JUMP = "cuphead_jump";
static const std::string CUPHEAD_DEATH = "cuphead_death";
}

namespace cagney{
static const std::string CAGNEY_FIRING_SEEDS = "cagney_firing_seeds";
static const std::string CAGNEY_INTRO_YELL = "cagney_intro_yell";
}
}

namespace assets{

namespace images{
static const char* BACKGROUND = "assets/background.png";
static const char* BRAVO_IMAGE = "assets/ui/bravo.png";
static const char* FLOWERS = "assets/flowers.png";
static const char* GRASS = "assets/grass.png";
static const char* FAVICON = "assets/icon.bmp";
static const char* LANDING_ONE =  "assets/landing3.png";
static const char* LANDING_TWO =  "assets/landing2.png";

static const char* LIFE_FILLED = "assets/life_filled.png";
static const char* LIFE_DARK = "assets/life_dark.png";
}

namespace audio{
static const char* MAIN_THEME = "assets/audio/cuphead_ost_floral_fury.mp3";
static const char* CUPHEAD_ATTACK = "assets/cuphead/sounds/player_spreadshot_fire_loop.wav";
static const char* CUPHEAD_DEATH = "assets/cuphead/sounds/player_death_01.wav";
static const char* CUPHEAD_JUMP = "assets/cuphead/sounds/player_jump_01.wav";
static const char* CAGNEY_FIRING_SEEDS = "assets/cagney/sounds/flower_gattling_loop.wav";
static const char* CAGNEY_INTRO_YELL = "assets/cagney/sounds/flower_intro_yell.wav";
static const char* PLAYER_HIT = "assets/audio/player_hit_01.wav";
static const char* GAME_OVER = "assets/audio/player_game_over.wav";
}
}
}

