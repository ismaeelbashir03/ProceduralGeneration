#include <vector>
#include <utility>
#include <iostream>
#include "StarSystem.h"

using namespace std;

void clear() {
    for (int i; i < 100; i++) {
        cout << endl;
    }
}

int main() {
    coordinates_t coords = std::make_pair(static_cast<uint32_t>(0), static_cast<uint32_t>(0));
    vector<pair<int, int> > dirs;
    dirs.push_back(std::make_pair(1, 0));
    dirs.push_back(std::make_pair(-1, 0));
    dirs.push_back(std::make_pair(0, 1));
    dirs.push_back(std::make_pair(0, -1));
    vector<string> move_dirs;
    move_dirs.push_back("Right");
    move_dirs.push_back("Left");
    move_dirs.push_back("Down");
    move_dirs.push_back("Up");
    string indent = "   ";

    while (true) {
        // generate current star
        StarSystem current(coords, false);

        // generate surrounding stars
        vector<StarSystem> neighbors;
        for (pair<int, int> dir: dirs) {
            coordinates_t n_coords = std::make_pair(static_cast<uint32_t>(coords.first + dir.first), static_cast<uint32_t>(coords.second + dir.second));
            StarSystem nei(n_coords, false);
            neighbors.push_back(nei);
        }

        // print location
        cout << "Location: " << coords.first << ", " << coords.second << endl;

        // print star details
        cout << endl;
        if (current.exists) {
            cout << "Star System: " << endl;
            cout << indent << "Size: " << current.diameter << endl;
            cout << indent << "Color: " << current.color << endl;
        }
        else {
            cout << "empty space..." << endl;
        }

        cout << "Neighboring stars:" << endl;
        // print neighbor stars
        int index = 0;
        for (StarSystem nei: neighbors) {
            if (nei.exists) {
                cout << index << ". (" << move_dirs[index] << ") " << "System exists" << endl;
            }
            else {
                cout << index << ". (" << move_dirs[index] << ") " << "empty space here" << endl;
            }
            index++;
        }

        //prompt to enter star
        if (current.exists) {
            cout << "5. (enter system) " << endl;
        }

        // go to next location
        int input;
        std::cin >> input;

        // enter system
        if (input == 5) {
            // generate planets
            StarSystem current(coords, true);

            while (true) {
                clear();

                cout << "Location: " << coords.first << ", " << coords.second << endl;
                vector<Planet> planets = current.planets;

                for (int i; i < planets.size(); i++) {
                    cout << "Planet:" << endl;
                    cout << indent << "Size:" << planets[i].diameter << endl;
                    cout << indent << "Water (%):" << planets[i].water << endl;
                    cout << indent << "Temprature (c):" << planets[i].temprature << endl;
                    cout << indent << "Population:" << planets[i].population << endl;
                    cout << endl;
                }
                cout << "1. Exit" << endl;

                std::cin >> input;
                if (input == 1) {
                    clear();
                    break;
                } else {
                    cout << "Please enter only 1 to exit" << endl;
                }
            }
        }
        // move
        else if (input >= 0 && input < dirs.size()) {
            uint32_t x = coords.first + dirs[input].first;
            uint32_t y = coords.second + dirs[input].second;
            coords = std::make_pair(static_cast<uint32_t>(x), static_cast<uint32_t>(y));
            clear();
        } 
        // input validation
        else {
            cout << "Invalid input. Please enter a number from 0-4 or 5 to enter a star if it exists." << endl;
        }
    }
    
    return 0;
}