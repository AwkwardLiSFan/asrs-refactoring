/*
 * example4-eclipse.h
 *
 *  Created on: 21 Jan 2022
 *      Author: a1790800
 */

#ifndef EXAMPLE4_ECLIPSE_H_
#define EXAMPLE4_ECLIPSE_H_

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
		vector<int> crate_piles = { numCrates }; // @suppress("Invalid arguments")
		vector<int> new_piles;

		while (crate_piles.size() > 0) {
			for (int pile : crate_piles) {
				int half = pile / 2;
				if (pile % 2 == 1) {
					new_piles.push_back(half + 1);
					new_piles.push_back(half);
				} else {
					new_piles.push_back(half);
					new_piles.push_back(half);
				}
			}
			crate_piles.clear();

			for (int pile : new_piles) {
				if (pile <= loadSize) {
					complete++;
				} else {
					crate_piles.push_back(pile);
				}
			}
			new_piles.clear();
		}

		return complete;
	}

};

#endif /* EXAMPLE4_ECLIPSE_H_ */
