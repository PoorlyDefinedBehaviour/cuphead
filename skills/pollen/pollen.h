#pragma once
#include "skills/skill.h"

class Pollen : public Skill
{
public:
    Pollen(Entity* entity);
    void update();
};

