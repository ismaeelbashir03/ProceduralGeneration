#pragma once
#include <iostream>

using coordinates_t = std::pair<uint32_t, uint32_t>;
using diameter_t = std::double_t;
using color_t = uint32_t;

const color_t starColors[8] = {
    0xFFFFFFFF, 0xFFD9FFFF, 0xFFA3FFFF, 0xFFFFC8C8,
    0xFFFFCB9D, 0xFF9F9FFF, 0xFF415EFF, 0xFF281990
};