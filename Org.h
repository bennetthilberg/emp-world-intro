#ifndef ORG_H
#define ORG_H

#include "emp/math/Random.hpp"
#include "emp/tools/string_utils.hpp"

class Organism {
  private:
    double points;
    emp::Ptr<emp::Random> random;
    int species;

  public:
    Organism(emp::Ptr<emp::Random> _random, double _points = 0.0,
             int _species = 0)
        : points(_points), random(_random) {
        species = _species;
    }

    void SetPoints(double _in) {
        points = _in;
    }
    void AddPoints(double _in) {
        points += _in;
    }
    int GetSpecies() {
        return species;
    }
    void Process(bool doIHaveCompany) {
        std::cout << "Processing" << std::endl;
        if(!doIHaveCompany){
            points += 50;
        }
    }
    emp::Ptr<Organism> CheckReproduction() {
        std::cout << "Checking reproduction" << std::endl;
        if (points > 1000) {
            std::cout << "Reproducing" << std::endl;
            emp::Ptr<Organism> offspring = new Organism(*this);
            offspring->SetPoints(0);
            points = 0;
            return offspring;
        }
        return nullptr;
    }
};
#endif