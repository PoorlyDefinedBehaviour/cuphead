#pragma once
#include "skills/skill.h"

class Boomerang : public Skill
{
public:
    Boomerang(Entity* entity);
    auto update() -> void;
};
