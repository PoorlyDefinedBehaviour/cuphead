#pragma once

class Collision
{
public:
    Collision() = delete;
    template<typename F, typename S> static auto AABB(F* first, S* second) -> bool
    {
        return first->position.x + first->getDimensions().x > second->position.x and
                first->position.x < second->position.x + second->getDimensions().x and
                first->position.y + first->getDimensions().y > second->position.y and
                first->position.y < second->position.y + second->getDimensions().y;
    }

    template<typename F, typename S> static auto WOBAABB(F* first, S* second) -> bool
    {
        return  first->position.x - 20 + first->getDimensions().x > second->position.x and
                first->position.x <  second->position.x - 20 + second->getDimensions().x and
                first->position.y + 25 + first->getDimensions().y > second->position.y and
                first->position.y < second->position.y + second->getDimensions().y;
    }
};

