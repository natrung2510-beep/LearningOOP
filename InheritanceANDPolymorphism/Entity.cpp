#include "Entity.h"
float Entity::takeDamage(float damage)
{
    hp -= this->calculateDamage(damage);
    return (hp < 0) ? 0 : hp;
}