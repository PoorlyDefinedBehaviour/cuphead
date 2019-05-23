#pragma once
#include "skills/skill.h"

class Entity;

class Ray : public Skill
{
public:
    Ray(Entity* entity);
};

