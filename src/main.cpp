#include <iostream>
#include "StarSystem.h"

using namespace std;

int main() {

    for (int i = 0; i < 1000; i++) {
        coordinates_t coords = std::make_pair(static_cast<uint32_t>(i), static_cast<uint32_t>(i*i));
        StarSystem ss(coords);
        cout << "Exists: " << ss.exists << " Color: " << ss.color << " Size: " << ss.diameter << endl;
    }
    return 0;
}