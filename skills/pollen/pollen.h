#pragma once
#include "skills/skill.h"

class Pollen : public Skill
{
public:
    Pollen(Entity* entity);
    auto update() -> void;
};

