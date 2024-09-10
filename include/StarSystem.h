#pragma once
#include "RandomNumber.h"
#include "Types.h"
#include "Config.h"

class StarSystem {
private:
    RandomNumber rn;

public:
    bool exists;
    diameter_t diameter;
    color_t color;

    StarSystem(coordinates_t coordinates) {
        // generate seed from coordinates
        Lehmer32_t seed = (coordinates.first & 0xFFFF) << 16 | (coordinates.second & 0xFFFF); 
        rn.setSeed(seed);

        // does the system exist
        this->exists = (rn.rndInt(0, STARSYSTEMPROB) == 1);
        if (!this->exists) return;

        // generate system features
        this->diameter = rn.rndDouble(MINSIZE, MAXSIZE);
        this->color = starColors[rn.rndInt(0, 8)];
    }
};