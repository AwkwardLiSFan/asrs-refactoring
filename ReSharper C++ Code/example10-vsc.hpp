#include <vector>
#include <unordered_set>    // this method does not correct
#include <set>
#include <algorithm>

using namespace std;

using VI = vector<int>;
using VVI = vector<vector<int>>;

class FriendlySequences
{
public:
	int count(VI array)
	{
		int cnt = 0;
		VVI all_seqs = FindAllSequences(array);
		for (auto seq : all_seqs)
		{
			if (CheckFriendlySequence(seq))
			{
				cnt ++;
			}
		}
		return cnt;
	}

private:
	VVI FindAllSequences(VI arr)
	{
		VI seq;
		VVI seqs;
		for (int i = 0; i < static_cast<int>(arr.size()); i++)
		{
			VI seq = {arr.at(i)};
			for (int j = i + 1; j < static_cast<int>(arr.size()); j++)
			{
				seq.push_back(arr.at(j));
				seqs.push_back(seq);
			}
		}
		return seqs;
	}

	VI num2digit(int x)
	{
		VI digits;
		while (x)
		{
			digits.push_back(x % 10);
			x /= 10;
		}
		reverse(digits.begin(), digits.end());
		return digits;
	}

	set<int> num2set(int x)
	{
		set<int> digits;
		while (x)
		{
			digits.insert(x % 10);
			x /= 10;
		}
		return digits;
	}

	// optimise shorter code
	bool CheckFriendlySequence(VI seq)
	{
		set<int> digits = num2set(seq.at(0));
		int sz = seq.size();
		for (int i = 1; i < sz; i++)
		{
			set<int> tmp_digits = num2set(seq.at(i));
			if (digits != tmp_digits) return false;
		}
		return true;
	}
};
