#ifndef ARROWS_H
#define ARROWS_H

#include <iostream>
#include <string>

using namespace std;

class Arrows {
public:
    int arrowLength(string s, int index, char head) {
        int count_arrows;

        if (head == '<') {
            count_arrows = 1;

            for (int i = index + 1; i < s.size(); i++) {
                if (s[i] == s[index + 1] && s[i] != '<' && s[i] != '>') {
                    count_arrows++;
                } else if (s[i] == '<' || s[i] == '>') {
                    break;
                } else {
                    break;
                }
                //cout << count_arrows << endl;
            }
        } else if (head == '>') {
            count_arrows = 1;

            for (int i = index - 1; i >= 0; i--) {
                if (s[i] == s[index - 1] && s[i] != '<' && s[i] != '>') {
                    count_arrows++;
                } else if (s[i] == '<' || s[i] == '>') {
                    break;
                } else {
                    break;
                }
                //cout << count_arrows << endl;
            }
        }

        //cout << endl << count_arrows << endl;
        //cout << endl;

        return count_arrows;
    }

    int longestArrow(string s) {
        int max = -1;
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '<') {
                count = arrowLength(s, i, '<');
                if (count > max) {
                    max = count;
                }
            } else if (s[i] == '>') {
                count = arrowLength(s, i, '>');
                if (count > max) {
                    max = count;
                }
            }
        }

        return max;
    }
};

#endif
