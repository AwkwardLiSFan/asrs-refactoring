//
// Created by SohamS on 20/01/2022.
//

#ifndef UNTITLED_EXAMPLE3_CLION_H
#define UNTITLED_EXAMPLE3_CLION_H

#include <iostream>
#include <string>

using namespace std;

class Arrows {
public:

    int longestArrow(string s){
        int count = 0;
        int max = 0;

        // iterating through loop
        for(int i = 0; i<s.length(); i++) {

            // single left arrow
            if(s[i] == '<') {
                //max = 1;
                count++;
                if(s[i+1] == '-') {
                    //out << i+1 << " index -" <<endl;
                    count++;
                    for(int j = i+2; s.length(); j++){
                        if(s[j] != '-'){
                            break;
                        }

                        count++;

                    }
                }

                if(s[i+1] == '=') {
                    //cout << i+1 << " index =" <<endl;
                    count++;
                    for(int j = i+2; s.length(); j++){

                        if(s[j] != '='){
                            break;
                        }

                        count++;
                    }
                }
            }
            if(s[i] == '>'){
                //max = 1;
                count++;
                if(s[i-1] == '-') {
                    //cout << i-1 << " index -" <<endl;
                    count++;
                    for(int j = i-2; s.length(); j--){

                        if(s[j] != '-'){
                            break;
                        }

                        count++;
                    }
                }

                if(s[i-1] == '=') {
                    //cout << i-1 << " index =" <<endl;
                    count++;
                    for(int j = i-2; s.length(); j--){

                        if(s[j] != '='){
                            break;
                        }

                        count++;
                    }
                }
            }


            if(count > max) {

                max = count;

            }
            count = 0;
        }
        return max == 0 ? -1 : max;
    }

};

#endif //UNTITLED_EXAMPLE3_CLION_H
