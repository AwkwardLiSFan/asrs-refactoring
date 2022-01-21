/*
 * example5-eclipse.h
 *
 *  Created on: 21 Jan 2022
 *      Author: a1790800
 */

#ifndef ARROWS_H
#define ARROWS_H
#include <iostream>

#include <string>
#include <vector>

class Arrows {
public:
	int longestArrow(std::string s) {
		int slength = s.length();
		std::vector<int> arrowLengths;
		int count = 0;
		int count2 = 0;

		for (int i = 0; i < slength; i++) {
			int arrowLength = 0;
			if (s.at(i) == '<' && i + 1 < slength && s.at(i + 1) == '=') {
				int j = i + 1;
				arrowLength++;
				//std::cout << "working1" << std::endl;
				count++;
				while (s.at(j) == '=') {
					arrowLength++;
					j++;
					if (j >= slength) {
						break;
					}
				}
				arrowLengths.push_back(arrowLength);
			} else if (s.at(i) == '<' && i + 1 < slength
					&& s.at(i + 1) == '-') {
				int j = i + 1;
				arrowLength++;
				//std::cout << "working2" << std::endl;
				count++;
				while (s.at(j) == '-') {
					arrowLength++;
					j++;
					if (j >= slength) {
						break;
					}
				}
				arrowLengths.push_back(arrowLength);
			} else if (s.at(i) == '>' && i - 1 >= 0 && s.at(i - 1) == '-') {
				int j = i - 1;
				arrowLength++;
				//std::cout << "working3" << std::endl;
				count++;
				while (s.at(j) == '-') {
					arrowLength++;
					j--;
					if (j < 0) {
						break;
					}
				}
				arrowLengths.push_back(arrowLength);
			} else if (s.at(i) == '>' && i - 1 >= 0 && s.at(i - 1) == '=') {
				int j = i - 1;
				arrowLength++;
				//std::cout << "working4" << std::endl;
				count++;
				while (s.at(j) == '=') {
					arrowLength++;
					j--;
					if (j < 0) {
						break;
					}
				}
				arrowLengths.push_back(arrowLength);
			}
			if (s.at(i) == '<' || s.at(i) == '>') {
				count2++;
			}
			//std::cout << "working" << std::endl;
		}
		if (count2 == 0) {
			return -1;
		}
		if (count == 0) {
			return 1;
		}
		int max = -1;
		for (int i = 0; i < arrowLengths.size(); i++) {
			if (arrowLengths.at(i) > max) {
				max = arrowLengths.at(i);
			}
		}
		return max;
	}

};
#endif

