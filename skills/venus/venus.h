#pragma once
#include "skills/skill.h"
#include "entity/entity.h"

class Venus : public Skill
{
public:
    Venus(Entity* entity);
    auto update() -> void;

private:
    Entity* target;
};
