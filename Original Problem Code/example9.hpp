#ifndef BARBECUE_H
#define BARBECUE_H
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <sstream>

using namespace std;


class Barbecue
{
public:

	Barbecue();
	int eliminate(int n, vector<int> voter, vector<int> excluded);
};

#endif

Barbecue::Barbecue()
{

}

int Barbecue::eliminate(int n, vector<int> voter, vector<int> excluded)
{
	std::vector<int> elimination_tally(n, 0);
	std::vector<int> voting_tally(n, 0);


	if (n == 1)
	{
		return 0;
	}
	if (voter.size() == 1)
	{
		return excluded.at(0);
	}
	
	
	for (int i = 0; i < voter.size(); ++i)
	{
		voting_tally.at(voter.at(i))++;
	}

        //	ELIMINATION
	for (int i = 0; i < excluded.size(); ++i)
	{
		elimination_tally.at(excluded.at(i))++;
	}



	std::vector<int> tied_indexes;

	int max_index = *max_element(elimination_tally.rbegin(), elimination_tally.rend());
	int max = 0;

	// MAX VALUE
	for (int i = 0; i < elimination_tally.size(); ++i)
	{
		if (elimination_tally.at(i) >= max)
		{
			max = elimination_tally.at(i);
		}

		
	}

	for (int i = 0; i < elimination_tally.size(); ++i)
	{
		if (elimination_tally.at(i) == max)
		{
			tied_indexes.push_back(i);
		}
	}



	if (tied_indexes.size() == 1)
	{
		for (int i = 0; i < elimination_tally.size(); ++i)
		{
			if (elimination_tally.at(i) == max)
			{
				return i;
			}
		}

		
	}
	else
	{

		std::vector<int> tied_indexes_values;
		int max_tied_index = 0;
		for (int i = 0; i < tied_indexes.size(); ++i)
		{
			tied_indexes_values.push_back(voting_tally.at(tied_indexes.at(i)));
			if (voting_tally.at(tied_indexes.at(i)) >= max_tied_index)
			{
				max_tied_index = voting_tally.at(tied_indexes.at(i));
			}
			cout << "test " << tied_indexes_values.at(i) << endl;;
			
		}
		int max_index_tally = *max_element(tied_indexes_values.rbegin(), tied_indexes_values.rend());

		std::vector<int> tied_indexes_tied;
		for (int i = 0; i < tied_indexes_values.size(); ++i)
		{
			if (tied_indexes_values.at(i) == max_tied_index)
			{
				tied_indexes_tied.push_back(tied_indexes.at(i));
			}
		}


		if (tied_indexes_tied.size() == 1)
		{

			cout << "here" << "output: " << tied_indexes_tied.at(0)<<  endl;
			return tied_indexes_tied.at(0);
		}
		else
		{
			int min_thing = 200;

			for (int i = 0; i < tied_indexes.size(); ++i)
			{
				if (tied_indexes.at(i) < min_thing)
				{
					min_thing = tied_indexes.at(i);
				}
			}
			return min_thing;
		}


		
	}

	return max_index;
}


