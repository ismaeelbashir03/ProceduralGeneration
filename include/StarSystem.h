#pragma once
#include "RandomNumber.h"
#include "Types.h"
#include "Config.h"

struct Planet {
    diameter_t diameter = 0.0;
    double water = 0.0;
    double temprature = 0.0;
    double population = 0.0;
};

class StarSystem {
private:
    RandomNumber rn;

public:
    bool exists;
    diameter_t diameter;
    color_t color;
    std::vector<Planet> planets;

    StarSystem(coordinates_t coordinates, bool generatePlanets) {
        // generate seed from coordinates
        Lehmer32_t seed = (coordinates.first & 0xFFFF) << 16 | (coordinates.second & 0xFFFF); 
        rn.setSeed(seed);

        // does the system exist
        this->exists = (rn.rndInt(0, STARSYSTEMPROB) == 1);
        if (!this->exists) return;

        // generate system features
        this->diameter = rn.rndDouble(MINSIZE, MAXSIZE);
        this->color = starColors[rn.rndInt(0, 8)];

        if (!generatePlanets) return;
        // generate planets
        int nPlanets = rn.rndInt(0, 5);
        for (int i; i < nPlanets; i++) {
            Planet p;
            p.diameter = rn.rndDouble(4, 20);
            p.water = rn.rndInt(0, 100);
            p.temprature = rn.rndInt(-200, 300);
            p.population = std::max(rn.rndInt(-500000, 300000), 0);
            this->planets.push_back(p);
        }
    }
};