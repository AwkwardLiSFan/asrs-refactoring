#ifndef EXAMPLE3_VSC_HPP
#define EXAMPLE3_VSC_HPP
#include <iostream>
#include <string>

using namespace std;

class Arrows
{
public:
	int longestArrow(string s)
	{
		int count = 0;
		int max = 0;

		// iterating through loop
		for (int i = 0; i < s.length(); i++)
		{
			// single left arrow
			if (s[i] == '<')
			{
				//max = 1;
				count++;
				if (s[i + 1] == '-')
				{
					//out << i+1 << " index -" <<endl;
					count++;
					for (int j = i + 2; s.length(); j++)
					{
						if (s[j] != '-')
						{
							break;
						}

						count++;
					}
				}

				if (s[i + 1] == '=')
				{
					//cout << i+1 << " index =" <<endl;
					count++;
					for (int j = i + 2; s.length(); j++)
					{
						if (s[j] != '=')
						{
							break;
						}

						count++;
					}
				}
			}
			if (s[i] == '>')
			{
				//max = 1;
				count++;
				if (s[i - 1] == '-')
				{
					//cout << i-1 << " index -" <<endl;
					count++;
					for (int j = i - 2; s.length(); j--)
					{
						if (s[j] != '-')
						{
							break;
						}

						count++;
					}
				}

				if (s[i - 1] == '=')
				{
					//cout << i-1 << " index =" <<endl;
					count++;
					for (int j = i - 2; s.length(); j--)
					{
						if (s[j] != '=')
						{
							break;
						}

						count++;
					}
				}
			}


			if (count > max)
			{
				max = count;
			}
			count = 0;
		}
		return max == 0 ? -1 : max;
	}
};


#endif // EXAMPLE3_VSC_HPP

