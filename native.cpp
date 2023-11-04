#include <iostream>

#include "Org.h"
#include "emp/base/vector.hpp"
#include "emp/math/Random.hpp"
#include "emp/math/random_utils.hpp"

#include "World.h"

// This is the main function for the NATIVE version of this project.

int main(int argc, char* argv[]) {
    emp::Random random(2);
    OrgWorld world(random);
    Organism* new_org0 = new Organism(&random, 0, 0);
    Organism* new_org1 = new Organism(&random, 0, 1);
    Organism* new_org2 = new Organism(&random, 0, 2);
    world.Inject(*new_org0);
    world.Inject(*new_org1);
    world.Inject(*new_org2);
    std::cout << "world size to start (pre resize): " << world.size()
              << std::endl;
    world.Resize(10, 10);
    std::cout << "world size to start (pre resize): " << world.size()
              << std::endl;
    std::cout << "# orgs to start: " << world.GetNumOrgs() << std::endl;
    world.Update();

    for (int i = 0; i < 22; i++) {
        world.Update();
    }
}
