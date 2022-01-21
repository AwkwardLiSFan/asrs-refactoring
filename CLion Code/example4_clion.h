//
// Created by SohamS on 20/01/2022.
//

#ifndef UNTITLED_EXAMPLE4_CLION_H
#define UNTITLED_EXAMPLE4_CLION_H
#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Truckloads {

public:
    int numTrucks(int numCrates, int loadSize) {
        if (numCrates <= loadSize) {
            return 1;
        }

        int complete = 0;
        vector<int> crate_piles = { numCrates };
        vector<int> new_piles;

        while (crate_piles.size() > 0) {
            for (int pile : crate_piles) {
                int half = pile / 2;
                {
                    new_piles.push_back(pile % 2 == 1 ? half + 1 : half);
                    new_piles.push_back(half);
                }
            }
            crate_piles.clear();

            for (int pile : new_piles) {
                if (pile <= loadSize) {
                    complete++;
                }
                else {
                    crate_piles.push_back(pile);
                }
            }
            new_piles.clear();
        }

        return complete;
    }

};

#endif //UNTITLED_EXAMPLE4_CLION_H
