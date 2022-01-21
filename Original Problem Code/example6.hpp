#ifndef MAGICSPELL_HPP
#define MAGICSPELL_HPP

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class MagicSpell
{
public:
    string fixTheSpell(string spell)
    {

        vector<char> letters;
        vector<int> indexes;
        string az = "";

        for (int i = 0; i < spell.size(); i++)
        {
            if (spell.at(i) == 'A' || spell.at(i) == 'Z')
            {
                az += spell.at(i);
            }
            else
            {
                letters.push_back(spell.at(i));
                indexes.push_back(i);
            }
        }

        // cout << az << endl;

        //reverse string
        string reverse = "";
        int count = 0;

        while (count < az.size())
        {
            reverse += az.at((az.size() - 1) - count);
            count++;
        }

        // cout << reverse << endl;

        // for (int i = 0; i < indexes.size(); i++)
        // {
        //     cout << "Index: " << indexes.at(i) << endl;
        //     cout << "Letter: " << letters.at(i) << endl;
        // }

        string temp1 = "";
        string temp2 = "";

        for (int i = 0; i < indexes.size(); i++)
        {
            if (indexes.at(i) == 0)
            {

                reverse = letters.at(i) + reverse;
            }
            else if (indexes.at(i) == spell.size() - 1)
            {
                reverse += letters.at(i);
            }
            else
            {
                temp1 = reverse.substr(0, indexes.at(i));
                // cout << reverse << endl;
                // cout << "Temp 1 is " << temp1 << endl;
                temp2 = reverse.substr(indexes.at(i));
                // cout << "Temp 2 is " << temp2 << endl;
                reverse = temp1 + letters.at(i) + temp2;
            }
        }

        return reverse;
    }
};


