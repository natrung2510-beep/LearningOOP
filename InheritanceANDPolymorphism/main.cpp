#include <iostream>
#include <string>
#include "Entity.h"
#include "Zombie.h"
#include "IronGolem.h"
using namespace std;
int main()
{
    Entity **Arena = new Entity *[2];

    Arena[0] = new Zombie("Zombie Co", 100);
    Arena[1] = new IronGolem("Golem Lang", 150, 15);

    const float damage = 20;
    for (int i = 0; i < 2; i++)
    {
        Arena[i]->takeDamage(damage);
        Arena[i]->displayInformation();
        cout << "------------------------\n";
    }

    cout << "==== CLEARING THE ARENA ====\n";
    for (int i = 0; i < 2; i++)
        delete Arena[i];

    delete[] Arena;
    Arena = nullptr;
    cout << "Clear successfully!\n";

    cin.get();
    return 0;
}