#pragma once

#include <vector>
#include <string>

namespace animations {

static const std::vector<const char*> POWERUP_FRAMES = {
    "assets/Cagney/Creating Object/Special Effects/FX_C_01.png",
    "assets/Cagney/Creating Object/Special Effects/FX_C_02.png",
    "assets/Cagney/Creating Object/Special Effects/FX_C_03.png",
};

namespace projectiles {
static const std::string BLUE_MISSILE_SEED_LAUNCH;

static std::vector<const char*> BLUE_MISSILE_SEED_LAUNCH_ANIMATION_FRAMES = {"assets/Cagney/Firing Seeds/Seed Missiles/Blue/Missile_B_01.png",
                                                                             "assets/Cagney/Firing Seeds/Seed Missiles/Blue/Missile_B_02.png",
                                                                             "assets/Cagney/Firing Seeds/Seed Missiles/Blue/Missile_B_03.png",
                                                                             "assets/Cagney/Firing Seeds/Seed Missiles/Blue/Missile_B_04.png",
                                                                             "assets/Cagney/Firing Seeds/Seed Missiles/Blue/Missile_B_05.png",
                                                                             "assets/Cagney/Firing Seeds/Seed Missiles/Blue/Missile_B_06.png",
                                                                            };

static std::vector<const char*> SEED_MISSILE_ANIMATION_FRAMES = {"assets/Cagney/Firing Seeds/Venus Flytrap/Seed/Seed_Fall_A_01.png",
                                                                 "assets/Cagney/Firing Seeds/Venus Flytrap/Seed/Seed_Fall_A_02.png",
                                                                 "assets/Cagney/Firing Seeds/Venus Flytrap/Seed/Seed_Fall_A_03.png",
                                                                 "assets/Cagney/Firing Seeds/Venus Flytrap/Seed/Seed_Fall_A_04.png",
                                                                 "assets/Cagney/Firing Seeds/Venus Flytrap/Seed/Seed_Fall_A_05.png",
                                                                 "assets/Cagney/Firing Seeds/Venus Flytrap/Seed/Seed_Fall_A_06.png",
                                                                 "assets/Cagney/Firing Seeds/Venus Flytrap/Seed/Seed_Fall_A_07.png",
                                                                 "assets/Cagney/Firing Seeds/Venus Flytrap/Seed/Seed_Fall_A_08.png",
                                                                 "assets/Cagney/Firing Seeds/Venus Flytrap/Seed/Seed_Fall_A_09.png",
                                                                 "assets/Cagney/Firing Seeds/Venus Flytrap/Seed/Seed_Fall_A_10.png",
                                                                 "assets/Cagney/Firing Seeds/Venus Flytrap/Seed/Seed_Fall_A_11.png",
                                                                 "assets/Cagney/Firing Seeds/Venus Flytrap/Seed/Seed_Fall_A_12.png",
                                                                 "assets/Cagney/Firing Seeds/Venus Flytrap/Seed/Seed_Fall_A_13.png",
                                                                 "assets/Cagney/Firing Seeds/Venus Flytrap/Seed/Seed_Fall_A_14.png",
                                                                 "assets/Cagney/Firing Seeds/Venus Flytrap/Seed/Seed_Fall_A_15.png",
                                                                 "assets/Cagney/Firing Seeds/Venus Flytrap/Seed/Seed_Fall_A_16.png",
                                                                 "assets/Cagney/Firing Seeds/Venus Flytrap/Seed/Seed_Fall_A_17.png",
                                                                 "assets/Cagney/Firing Seeds/Venus Flytrap/Seed/Seed_Fall_A_18.png",
                                                                };

static std::vector<const char*> BOOMERANG_ANIMATION_FRAMES = {"assets/Cagney/Creating Object/Boomerang/Boomerang_01.png",
                                                              "assets/Cagney/Creating Object/Boomerang/Boomerang_02.png",
                                                              "assets/Cagney/Creating Object/Boomerang/Boomerang_03.png",
                                                              "assets/Cagney/Creating Object/Boomerang/Boomerang_04.png",
                                                              "assets/Cagney/Creating Object/Boomerang/Boomerang_05.png",
                                                              "assets/Cagney/Creating Object/Boomerang/Boomerang_06.png",
                                                              "assets/Cagney/Creating Object/Boomerang/Boomerang_07.png",
                                                              "assets/Cagney/Creating Object/Boomerang/Boomerang_08.png",
                                                             };

static std::vector<const char*> RAY_ANIMATION_FRAMES = {"assets/cuphead_ray.png"};

static std::vector<const char*> POLLEN_ANIMATION_FRAMES = {"assets/Cagney/Pollen/Pollen_A_1.png",
                                                           "assets/Cagney/Pollen/Pollen_A_2.png",
                                                           "assets/Cagney/Pollen/Pollen_A_3.png",
                                                           "assets/Cagney/Pollen/Pollen_A_4.png",
                                                           "assets/Cagney/Pollen/Pollen_A_5.png",
                                                          };

static std::vector<const char*> VENUS_FLYING_PLANT_ANIMATION_FRAMES = {"assets/Cagney/Firing Seeds/Venus Flytrap/Venus_01.png",
                                                                       "assets/Cagney/Firing Seeds/Venus Flytrap/Venus_02.png",
                                                                       "assets/Cagney/Firing Seeds/Venus Flytrap/Venus_03.png",
                                                                       "assets/Cagney/Firing Seeds/Venus Flytrap/Venus_04.png",
                                                                       "assets/Cagney/Firing Seeds/Venus Flytrap/Venus_05.png",
                                                                       "assets/Cagney/Firing Seeds/Venus Flytrap/Venus_06.png",
                                                                       "assets/Cagney/Firing Seeds/Venus Flytrap/Venus_07_A.png",
                                                                       "assets/Cagney/Firing Seeds/Venus Flytrap/Venus_07_B.png",
                                                                       "assets/Cagney/Firing Seeds/Venus Flytrap/Venus_08_A.png",
                                                                       "assets/Cagney/Firing Seeds/Venus Flytrap/Venus_08_B.png",
                                                                       "assets/Cagney/Firing Seeds/Venus Flytrap/Venus_08_C.png",
                                                                       "assets/Cagney/Firing Seeds/Venus Flytrap/Venus_09_A.png",
                                                                       "assets/Cagney/Firing Seeds/Venus Flytrap/Venus_09_B.png",
                                                                       "assets/Cagney/Firing Seeds/Venus Flytrap/Venus_10_A.png",
                                                                       "assets/Cagney/Firing Seeds/Venus Flytrap/Venus_11_A.png",
                                                                       "assets/Cagney/Firing Seeds/Venus Flytrap/Venus_11_B.png",
                                                                       "assets/Cagney/Firing Seeds/Venus Flytrap/Venus_12.png"
                                                                      };
}

namespace cuphead {

static const std::string IDLE = "idle";
static const std::string RUN = "cuphead_run";
static const std::string RUN_ATTACK = "cuphead_run_attack";
static const std::string JUMP = "cuphead_jump";
static const std::string ATTACK = "cuphead_default_attack";
static const std::string DEATH = "cuphead_death";
static const std::string PULLING_PANTS = "cuphead_pulling_pants";

static std::vector<const char*> PULLING_PANTS_ANIMATION_FRAMES = {"assets/cuphead/Intro/cuphead_intro_a_0001.png",
                                                                  "assets/cuphead/Intro/cuphead_intro_a_0002.png",
                                                                  "assets/cuphead/Intro/cuphead_intro_a_0003.png",
                                                                  "assets/cuphead/Intro/cuphead_intro_a_0004.png",
                                                                  "assets/cuphead/Intro/cuphead_intro_a_0005.png",
                                                                  "assets/cuphead/Intro/cuphead_intro_a_0006.png",
                                                                  "assets/cuphead/Intro/cuphead_intro_a_0007.png",
                                                                  "assets/cuphead/Intro/cuphead_intro_a_0008.png",
                                                                  "assets/cuphead/Intro/cuphead_intro_a_0009.png",
                                                                  "assets/cuphead/Intro/cuphead_intro_a_0010.png",
                                                                  "assets/cuphead/Intro/cuphead_intro_a_0011.png",
                                                                  "assets/cuphead/Intro/cuphead_intro_a_0012.png",
                                                                  "assets/cuphead/Intro/cuphead_intro_a_0013.png",
                                                                  "assets/cuphead/Intro/cuphead_intro_a_0014.png",
                                                                  "assets/cuphead/Intro/cuphead_intro_a_0015.png",
                                                                  "assets/cuphead/Intro/cuphead_intro_a_0016.png",
                                                                  "assets/cuphead/Intro/cuphead_intro_a_0017.png",
                                                                  "assets/cuphead/Intro/cuphead_intro_a_0018.png",
                                                                  "assets/cuphead/Intro/cuphead_intro_a_0019.png",
                                                                  "assets/cuphead/Intro/cuphead_intro_a_0020.png",
                                                                  "assets/cuphead/Intro/cuphead_intro_a_0021.png",
                                                                  "assets/cuphead/Intro/cuphead_intro_a_0022.png",
                                                                  "assets/cuphead/Intro/cuphead_intro_a_0023.png",
                                                                  "assets/cuphead/Intro/cuphead_intro_a_0024.png",
                                                                  "assets/cuphead/Intro/cuphead_intro_a_0025.png",
                                                                  "assets/cuphead/Intro/cuphead_intro_a_0026.png",
                                                                  "assets/cuphead/Intro/cuphead_intro_a_0027.png",
                                                                  "assets/cuphead/Intro/cuphead_intro_a_0028.png"
                                                                 };


static std::vector<const char*> IDLE_ANIMATION_FRAMES = {"assets/cuphead/Idle/cuphead_idle_0001.png",
                                                         "assets/cuphead/Idle/cuphead_idle_0002.png",
                                                         "assets/cuphead/Idle/cuphead_idle_0003.png",
                                                         "assets/cuphead/Idle/cuphead_idle_0004.png",
                                                         "assets/cuphead/Idle/cuphead_idle_0005.png",
                                                         "assets/cuphead/Idle/cuphead_idle_0004.png",
                                                         "assets/cuphead/Idle/cuphead_idle_0003.png",
                                                         "assets/cuphead/Idle/cuphead_idle_0002.png"
                                                        };

static std::vector<const char*> RUN_ANIMATION_FRAMES = {"assets/cuphead/Run/Normal/cuphead_run_0001.png",
                                                        "assets/cuphead/Run/Normal/cuphead_run_0002.png",
                                                        "assets/cuphead/Run/Normal/cuphead_run_0003.png",
                                                        "assets/cuphead/Run/Normal/cuphead_run_0004.png",
                                                        "assets/cuphead/Run/Normal/cuphead_run_0005.png",
                                                        "assets/cuphead/Run/Normal/cuphead_run_0006.png",
                                                        "assets/cuphead/Run/Normal/cuphead_run_0007.png",
                                                        "assets/cuphead/Run/Normal/cuphead_run_0008.png",
                                                        "assets/cuphead/Run/Normal/cuphead_run_0010.png",
                                                        "assets/cuphead/Run/Normal/cuphead_run_0011.png",
                                                        "assets/cuphead/Run/Normal/cuphead_run_0012.png",
                                                        "assets/cuphead/Run/Normal/cuphead_run_0013.png",
                                                        "assets/cuphead/Run/Normal/cuphead_run_0014.png",
                                                        "assets/cuphead/Run/Normal/cuphead_run_0015.png",
                                                        "assets/cuphead/Run/Normal/cuphead_run_0016.png"
                                                       };

static std::vector<const char*> JUMP_ANIMATION_FRAMES = {"assets/cuphead/Jump/cuphead_jump_0001.png",
                                                         "assets/cuphead/Jump/cuphead_jump_0002.png",
                                                         "assets/cuphead/Jump/cuphead_jump_0003.png",
                                                         "assets/cuphead/Jump/cuphead_jump_0004.png",
                                                         "assets/cuphead/Jump/cuphead_jump_0005.png",
                                                         "assets/cuphead/Jump/cuphead_jump_0006.png",
                                                         "assets/cuphead/Jump/cuphead_jump_0007.png",
                                                         "assets/cuphead/Jump/cuphead_jump_0008.png"
                                                        };


static std::vector<const char*> ATTACK_ANIMATION_FRAMES = {"assets/cuphead/Shoot/Straight/cuphead_shoot_straight_0001.png",
                                                           "assets/cuphead/Shoot/Straight/cuphead_shoot_straight_0002.png",
                                                           "assets/cuphead/Shoot/Straight/cuphead_shoot_straight_0003.png"
                                                          };

static std::vector<const char*> RUNNING_ATTACK_ANIMATION_FRAMES = {"assets/cuphead/Run/Shooting/Straight/cuphead_run_shoot_0001.png",
                                                                   "assets/cuphead/Run/Shooting/Straight/cuphead_run_shoot_0002.png",
                                                                   "assets/cuphead/Run/Shooting/Straight/cuphead_run_shoot_0003.png",
                                                                   "assets/cuphead/Run/Shooting/Straight/cuphead_run_shoot_0004.png",
                                                                   "assets/cuphead/Run/Shooting/Straight/cuphead_run_shoot_0005.png",
                                                                   "assets/cuphead/Run/Shooting/Straight/cuphead_run_shoot_0006.png",
                                                                   "assets/cuphead/Run/Shooting/Straight/cuphead_run_shoot_0007.png",
                                                                   "assets/cuphead/Run/Shooting/Straight/cuphead_run_shoot_0008.png",
                                                                   "assets/cuphead/Run/Shooting/Straight/cuphead_run_shoot_0009.png",
                                                                   "assets/cuphead/Run/Shooting/Straight/cuphead_run_shoot_0010.png",
                                                                   "assets/cuphead/Run/Shooting/Straight/cuphead_run_shoot_0011.png",
                                                                   "assets/cuphead/Run/Shooting/Straight/cuphead_run_shoot_0012.png",
                                                                   "assets/cuphead/Run/Shooting/Straight/cuphead_run_shoot_0013.png",
                                                                   "assets/cuphead/Run/Shooting/Straight/cuphead_run_shoot_0014.png",
                                                                   "assets/cuphead/Run/Shooting/Straight/cuphead_run_shoot_0015.png",
                                                                   "assets/cuphead/Run/Shooting/Straight/cuphead_run_shoot_0016.png"
                                                                  };

static std::vector<const char*> DEATH_ANIMATION_FRAMES = {
    "assets/cuphead/Death/cuphead_death_body_0001.png",
    "assets/cuphead/Death/cuphead_death_body_0002.png",
    "assets/cuphead/Death/cuphead_death_body_0003.png",
    "assets/cuphead/Death/cuphead_death_body_0004.png",
    "assets/cuphead/Death/cuphead_death_body_0005.png",
    "assets/cuphead/Death/cuphead_death_body_0006.png",
    "assets/cuphead/Death/cuphead_death_body_0007.png",
    "assets/cuphead/Death/cuphead_death_body_0008.png",
    "assets/cuphead/Death/cuphead_death_body_0009.png",
    "assets/cuphead/Death/cuphead_death_body_0010.png",
    "assets/cuphead/Death/cuphead_death_body_0011.png",
    "assets/cuphead/Death/cuphead_death_body_0012.png",
    "assets/cuphead/Death/cuphead_death_body_0013.png",
    "assets/cuphead/Death/cuphead_death_body_0014.png",
    "assets/cuphead/Death/cuphead_death_body_0015.png",
    "assets/cuphead/Death/cuphead_death_body_0016.png",
    "assets/cuphead/Ghost/cuphead_ghost_0001.png",
    "assets/cuphead/Ghost/cuphead_ghost_0002.png",
    "assets/cuphead/Ghost/cuphead_ghost_0003.png",
    "assets/cuphead/Ghost/cuphead_ghost_0004.png",
    "assets/cuphead/Ghost/cuphead_ghost_0005.png",
    "assets/cuphead/Ghost/cuphead_ghost_0006.png",
    "assets/cuphead/Ghost/cuphead_ghost_0007.png",
    "assets/cuphead/Ghost/cuphead_ghost_0008.png",
    "assets/cuphead/Ghost/cuphead_ghost_0009.png",
    "assets/cuphead/Ghost/cuphead_ghost_0010.png",
    "assets/cuphead/Ghost/cuphead_ghost_0011.png",
    "assets/cuphead/Ghost/cuphead_ghost_0012.png",
    "assets/cuphead/Ghost/cuphead_ghost_0013.png",
    "assets/cuphead/Ghost/cuphead_ghost_0014.png",
    "assets/cuphead/Ghost/cuphead_ghost_0015.png",
    "assets/cuphead/Ghost/cuphead_ghost_0016.png",
    "assets/cuphead/Ghost/cuphead_ghost_0017.png",
    "assets/cuphead/Ghost/cuphead_ghost_0018.png",
    "assets/cuphead/Ghost/cuphead_ghost_0019.png",
    "assets/cuphead/Ghost/cuphead_ghost_0020.png",
    "assets/cuphead/Ghost/cuphead_ghost_0021.png",
    "assets/cuphead/Ghost/cuphead_ghost_0022.png",
    "assets/cuphead/Ghost/cuphead_ghost_0023.png",
    "assets/cuphead/Ghost/cuphead_ghost_0024.png",
    "assets/cuphead/Ghost/cuphead_revive_0001.png",
    "assets/cuphead/Ghost/cuphead_revive_0002.png",
    "assets/cuphead/Ghost/cuphead_revive_0003.png",
    "assets/cuphead/Ghost/cuphead_revive_0004.png",
    "assets/cuphead/Ghost/cuphead_revive_0005.png",
    "assets/cuphead/Ghost/cuphead_revive_0006.png",
    "assets/cuphead/Ghost/cuphead_revive_0007.png",
    "assets/cuphead/Ghost/cuphead_revive_0008.png",
    "assets/cuphead/Ghost/cuphead_revive_0009.png",
    "assets/cuphead/Ghost/cuphead_revive_0010.png",
    "assets/cuphead/Ghost/cuphead_revive_0011.png",
    "assets/cuphead/Ghost/cuphead_revive_0012.png",
    "assets/cuphead/Ghost/cuphead_revive_0013.png",
    "assets/cuphead/Ghost/cuphead_revive_0014.png",
    "assets/cuphead/Ghost/cuphead_revive_0015.png",
    "assets/cuphead/Ghost/cuphead_revive_0016.png",
    "assets/cuphead/Ghost/cuphead_revive_0017.png",
    "assets/cuphead/Ghost/cuphead_revive_0018.png",
    "assets/cuphead/Ghost/cuphead_revive_0019.png",
    "assets/cuphead/Ghost/cuphead_revive_0021.png",
    "assets/cuphead/Ghost/cuphead_revive_0022.png",
    "assets/cuphead/Ghost/cuphead_revive_finale_0001.png",
    "assets/cuphead/Ghost/cuphead_revive_finale_0002.png",
    "assets/cuphead/Ghost/cuphead_revive_finale_0003.png",
    "assets/cuphead/Ghost/cuphead_revive_finale_0004.png",
    "assets/cuphead/Ghost/cuphead_revive_finale_0005.png",
    "assets/cuphead/Ghost/cuphead_revive_finale_0006.png"
};
}

namespace cagney {

static const std::string INTRO = "cagney_intro";
static const std::string IDLE = "idle";
static const std::string DEATH = "cagney_death";
static const std::string CREATE_OBJECT = "cagney_create_object";
static const std::string FIRING_SEEDS = "cagney_firing_missile";

static std::vector<const char*> INTRO_ANIMATION_FRAMES = {"assets/Cagney/Intro/Intro_01.png",
                                                          "assets/Cagney/Intro/Intro_02.png",
                                                          "assets/Cagney/Intro/Intro_03.png",
                                                          "assets/Cagney/Intro/Intro_04.png",
                                                          "assets/Cagney/Intro/Intro_05.png",
                                                          "assets/Cagney/Intro/Intro_06.png",
                                                          "assets/Cagney/Intro/Intro_07.png",
                                                          "assets/Cagney/Intro/Intro_08.png",
                                                          "assets/Cagney/Intro/Intro_09.png",
                                                          "assets/Cagney/Intro/Intro_10.png",
                                                          "assets/Cagney/Intro/Intro_11.png",
                                                          "assets/Cagney/Intro/Intro_12.png",
                                                          "assets/Cagney/Intro/Intro_13.png",
                                                          "assets/Cagney/Intro/Intro_14.png",
                                                          "assets/Cagney/Intro/Intro_15.png",
                                                          "assets/Cagney/Intro/Intro_16.png",
                                                          "assets/Cagney/Intro/Intro_17.png",
                                                          "assets/Cagney/Intro/Intro_19.png",
                                                          "assets/Cagney/Intro/Intro_19.png",
                                                          "assets/Cagney/Intro/Intro_20.png"
                                                         };

static std::vector<const char*> IDLE_ANIMATION_FRAMES = {"assets/Cagney/Idle/Idle_01.png",
                                                         "assets/Cagney/Idle/Idle_02.png",
                                                         "assets/Cagney/Idle/Idle_03.png",
                                                         "assets/Cagney/Idle/Idle_04.png",
                                                         "assets/Cagney/Idle/Idle_05.png",
                                                         "assets/Cagney/Idle/Idle_06.png",
                                                         "assets/Cagney/Idle/Idle_07.png",
                                                         "assets/Cagney/Idle/Idle_08.png",
                                                         "assets/Cagney/Idle/Idle_09.png",
                                                         "assets/Cagney/Idle/Idle_10.png",
                                                         "assets/Cagney/Idle/Idle_11.png",
                                                         "assets/Cagney/Idle/Idle_12.png",
                                                         "assets/Cagney/Idle/Idle_13.png",
                                                         "assets/Cagney/Idle/Idle_14.png",
                                                         "assets/Cagney/Idle/Idle_15.png",
                                                         "assets/Cagney/Idle/Idle_16.png",
                                                         "assets/Cagney/Idle/Idle_17.png",
                                                         "assets/Cagney/Idle/Idle_18.png",
                                                         "assets/Cagney/Idle/Idle_19.png",
                                                         "assets/Cagney/Idle/Idle_20.png",
                                                         "assets/Cagney/Idle/Idle_21.png",
                                                         "assets/Cagney/Idle/Idle_22.png",
                                                         "assets/Cagney/Idle/Idle_23.png",
                                                         "assets/Cagney/Idle/Idle_24.png",
                                                        };

static std::vector<const char*> DEATH_ANIMATION_FRAMES = {"assets/Cagney/Death/Death_01.png",
                                                          "assets/Cagney/Death/Death_02.png",
                                                          "assets/Cagney/Death/Death_03.png",
                                                          "assets/Cagney/Death/Death_04.png",
                                                          "assets/Cagney/Death/Death_05.png",
                                                          "assets/Cagney/Death/Death_06.png",
                                                          "assets/Cagney/Death/Death_07.png",
                                                          "assets/Cagney/Death/Death_08.png",
                                                          "assets/Cagney/Death/Death_09.png",
                                                          "assets/Cagney/Death/Death_10.png",
                                                          "assets/Cagney/Death/Death_11.png",
                                                          "assets/Cagney/Death/Death_12.png",
                                                         };

static std::vector<const char*> CREATE_OBJECT_ANIMATION_FRAMES = {"assets/Cagney/Creating Object/Create_01.png",
                                                                  "assets/Cagney/Creating Object/Create_02.png",
                                                                  "assets/Cagney/Creating Object/Create_03.png",
                                                                  "assets/Cagney/Creating Object/Create_04.png",
                                                                  "assets/Cagney/Creating Object/Create_05.png",
                                                                  "assets/Cagney/Creating Object/Create_06.png",
                                                                  "assets/Cagney/Creating Object/Create_07.png",
                                                                  "assets/Cagney/Creating Object/Create_08.png",
                                                                  "assets/Cagney/Creating Object/Create_09.png",
                                                                  "assets/Cagney/Creating Object/Create_10.png",
                                                                  "assets/Cagney/Creating Object/Create_11.png",
                                                                  "assets/Cagney/Creating Object/Create_12.png",
                                                                  "assets/Cagney/Creating Object/Create_13.png",
                                                                  "assets/Cagney/Creating Object/Create_14.png",
                                                                  "assets/Cagney/Creating Object/Create_15.png",
                                                                  "assets/Cagney/Creating Object/Create_16.png",
                                                                  "assets/Cagney/Creating Object/Create_17.png",
                                                                  "assets/Cagney/Creating Object/Create_18.png",
                                                                  "assets/Cagney/Creating Object/Create_19.png",
                                                                  "assets/Cagney/Creating Object/Create_20.png",
                                                                  "assets/Cagney/Creating Object/Create_21a.png",
                                                                  "assets/Cagney/Creating Object/Create_22.png",
                                                                  "assets/Cagney/Creating Object/Create_23.png",
                                                                  "assets/Cagney/Creating Object/Create_24.png",
                                                                  "assets/Cagney/Creating Object/Create_25.png",
                                                                  "assets/Cagney/Creating Object/Create_26.png",
                                                                  "assets/Cagney/Creating Object/Create_x.png",
                                                                 };

static std::vector<const char*> FIRING_SEEDS_ANIMATION_FRAMES = {"assets/Cagney/Firing Seeds/FS_01.png",
                                                                 "assets/Cagney/Firing Seeds/FS_02.png",
                                                                 "assets/Cagney/Firing Seeds/FS_03.png",
                                                                 "assets/Cagney/Firing Seeds/FS_04.png",
                                                                 "assets/Cagney/Firing Seeds/FS_05.png",
                                                                 "assets/Cagney/Firing Seeds/FS_06.png",
                                                                 "assets/Cagney/Firing Seeds/FS_07.png",
                                                                 "assets/Cagney/Firing Seeds/FS_08.png",
                                                                 "assets/Cagney/Firing Seeds/FS_09.png",
                                                                 "assets/Cagney/Firing Seeds/FS_10.png",
                                                                 "assets/Cagney/Firing Seeds/FS_11.png",
                                                                 "assets/Cagney/Firing Seeds/FS_12.png",
                                                                 "assets/Cagney/Firing Seeds/FS_13.png",
                                                                 "assets/Cagney/Firing Seeds/FS_14.png",
                                                                 "assets/Cagney/Firing Seeds/FS_15.png",
                                                                 "assets/Cagney/Firing Seeds/FS_16.png",
                                                                 "assets/Cagney/Firing Seeds/FS_17.png",
                                                                 "assets/Cagney/Firing Seeds/FS_18.png",
                                                                 "assets/Cagney/Firing Seeds/FS_19.png",
                                                                 "assets/Cagney/Firing Seeds/FS_20.png",
                                                                 "assets/Cagney/Firing Seeds/FS_21.png",
                                                                 "assets/Cagney/Firing Seeds/FS_22.png"
                                                                };
}
}
