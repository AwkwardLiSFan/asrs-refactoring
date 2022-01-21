#include <iostream>
#include <string>
#include <vector>
using namespace std;

class GoodHours
{
public:
	int howMany(string beforeTime, string afterTime)
	{
		// Converting from string to int
		vector<int> vec_BT, vec_AT;

		vec_BT.push_back(beforeTime.at(0) - '0');
		vec_BT.push_back(beforeTime.at(1) - '0');
		vec_BT.push_back(beforeTime.at(3) - '0');
		vec_BT.push_back(beforeTime.at(4) - '0');

		vec_AT.push_back(afterTime.at(0) - '0');
		vec_AT.push_back(afterTime.at(1) - '0');
		vec_AT.push_back(afterTime.at(3) - '0');
		vec_AT.push_back(afterTime.at(4) - '0');


		// Finding difference between both times
		int difference = 1, BT_hours, BT_mins, BT_total, AT_hours, AT_mins, AT_total;
		BT_hours = vec_BT[0] * 10 + vec_BT[1]; // 2 * 10 = 20 + 3 = 23:00
		BT_mins = vec_BT[2] * 10 + vec_BT[3]; // 3 * 10 = 30 + 5 = 00:35
		AT_hours = vec_AT[0] * 10 + vec_AT[1];
		AT_mins = vec_AT[2] * 10 + vec_AT[3];

		BT_total = BT_hours * 60 + BT_mins; // 23 * 60 = 1380 mins + 35 = 1415 mins
		AT_total = AT_hours * 60 + AT_mins;

		if (BT_total < AT_total)
		{
			difference = AT_total - BT_total;
		}
		else if (BT_total > AT_total)
		{
			difference = (1440 - BT_total) + AT_total;
		}


		// Incrementing the times and making comparisions
		if (vec_BT.at(0) == (vec_BT.at(1) * vec_BT.at(2) * vec_BT.at(3)))
		{
			goodTimes++;
		}
		else if ((vec_BT.at(0) * vec_BT.at(1)) == (vec_BT.at(2) * vec_BT.at(3)))
		{
			goodTimes++;
		}
		else if ((vec_BT.at(0) * vec_BT.at(1) * vec_BT.at(2)) == vec_BT.at(3))
		{
			goodTimes++;
		}

		// Time incrementer
		vec_BT.at(3)++; // Adds one minute

		if (vec_BT.at(3) > 9)
		{
			// Checks if the ones in the minute section is more than one digit
			vec_BT.at(2)++; // Increments the tens section and resets the ones section
			vec_BT.at(3) = 0;
		}

		if (vec_BT.at(2) == 6)
		{
			// if the minutes reach 60, increment hours by 1 and change minutes back to 00
			vec_BT.at(2) = 0;
			vec_BT.at(1)++;
		}

		if (vec_BT.at(1) > 9)
		{
			// if the ones in the hour section is more than one,
			vec_BT.at(0)++; // increments the tens section and resets the ones section
			vec_BT.at(1) = 0;
		}

		if (vec_BT.at(0) == 2 && vec_BT.at(1) == 4)
		{
			// If the hours reach 24:00, sets it to 00:00
			vec_BT.at(0) = 0;
			vec_BT.at(1) = 0;
		}

		difference--;
	}

	return
	goodTimes;
}

};
