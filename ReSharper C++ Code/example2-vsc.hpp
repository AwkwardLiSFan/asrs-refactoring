using namespace std;
#include <vector>
#include <string>
#include <algorithm>

class GoodHours
{
public:
	int howMany(string beforeTime, string afterTime)
	{
		// intialize
		int goodTimes = 0;
		int H1, H2, M1, M2;

		// convert strings to integer vectors
		vector<int> before, after;
		for (int i = 0; i < 5; i++)
		{
			// convert everything but ':' to an int
			if (i != 2)
			{
				before.push_back(beforeTime[i] - '0');
				after.push_back(afterTime[i] - '0');
			}
		}


		// continue incrementing until we reach specified time 'after'
		while (before != after)
		{
			// set time
			H1 = before[0];
			H2 = before[1];
			M1 = before[2];
			M2 = before[3];

			// check if time is 'Good'
			if (isGood(H1, H2, M1, M2) == true)
				goodTimes++;

			// increment M2
			before[3]++;

			// if M2 == 10, reset to 0 and increment M1
			if (before[3] == 10)
			{
				before[3] = 0;
				before[2]++;
			}

			// if M1 == 6, reset to 0 and increment H2
			if (before[2] == 6)
			{
				before[2] = 0;
				before[1]++;
			}

			// if (H2 == 10) or if (H2 == 5 && H1 == 2), reset to 0 and increment H1
			if (before[1] == 10 || before[1] == 4 && before[0] == 2)
			{
				before[1] = 0;
				before[0]++;
			}

			// if H1 == 3, reset to 0
			if (before[0] == 3)
			{
				before[0] = 0;
			}
		}

		// check on the final time
		H1 = after[0];
		H2 = after[1];
		M1 = after[2];
		M2 = after[3];
		if (isGood(H1, H2, M1, M2) == true)
			goodTimes++;

		// return solution
		return goodTimes;
	}


	// checks if time is 'Good' - product of the split time is equal
	bool isGood(int H1, int H2, int M1, int M2)
	{
		// H and H:MM
		if (H1 == H2 * M1 * M2)
			return true;

		// HH and MM
		if (H1 * H2 == M1 * M2)
			return true;

		// HH:M and M
		return H1 * H2 * M1 == M2 ? true : false;
	}
};
