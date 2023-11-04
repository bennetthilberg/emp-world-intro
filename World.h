#ifndef WORLD_H
#define WORLD_H
#include "emp/Evolve/World.hpp"
#include "emp/math/Random.hpp"
#include "emp/math/random_utils.hpp"
#include "Org.h"

class OrgWorld : public emp::World<Organism> {

    emp::Random &random;
    emp::Ptr<emp::Random> random_ptr;

  public:
    OrgWorld(emp::Random &_random)
        : emp::World<Organism>(_random), random(_random) {
        random_ptr.New(_random);
    }

    ~OrgWorld() {
    }

    void Update() {
        emp::World<Organism>::Update();
        std::cout << "# orgs: " << GetNumOrgs() << std::endl;
        emp::vector<size_t> processSchedule = emp::GetPermutation(random, GetSize());
        for(int i : processSchedule){
            if(!pop[i] || !IsOccupied(i)){
                continue;
            }
            if(pop[i]){
                pop[i]->Process();
            }
        }
        emp::vector<size_t> reproductionSchedule = emp::GetPermutation(random, GetSize());
        for(int i : reproductionSchedule){
            if(!pop[i] || !IsOccupied(i)){
                continue;
            }
            emp::Ptr<Organism> offspring = pop[i]->CheckReproduction();
            if(offspring){
                DoBirth(*offspring, i); 
            }
        }
        std::cout << "Update done" << std::endl;
    }

};
#endif