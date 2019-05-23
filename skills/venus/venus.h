#pragma once
#include "skills/skill.h"
#include "entity/entity.h"

class Venus : public Skill
{
public:
    Venus(Entity* entity);
    void update();

private:
    Entity* target;
};
