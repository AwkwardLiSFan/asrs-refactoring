/*
 * example10-eclipse.h
 *
 *  Created on: 21 Jan 2022
 *      Author: a1790800
 */

#ifndef EXAMPLE10_ECLIPSE_H_
#define EXAMPLE10_ECLIPSE_H_

#include <vector>
#include <unordered_set>    // this method does not correct
#include <set>
#include <algorithm>

using namespace std;

typedef vector<int> VI;
typedef vector<vector<int>> VVI;

class FriendlySequences {
public:
	int count(VI array) {
		int cnt = 0;
		VVI all_seqs = FindAllSequences(array);
		for (auto seq : all_seqs) {
			if (CheckFriendlySequence(seq)) {
				cnt++;
			}
		}
		return cnt;
	}
private:
	VVI FindAllSequences(VI arr) {
		VI seq;
		VVI seqs;
		for (int i = 0; i < (int) arr.size(); i++) {
			VI seq = { arr.at(i) }; // @suppress("Invalid arguments")
			for (int j = i + 1; j < (int) arr.size(); j++) {
				seq.push_back(arr.at(j));
				seqs.push_back(seq);
			}
		}
		return seqs;
	}
	VI num2digit(int x) {
		VI digits;
		while (x) {
			digits.push_back(x % 10);
			x /= 10;
		}
		reverse(digits.begin(), digits.end());
		return digits;
	}
	set<int> num2set(int x) {
		set<int> digits;
		while (x) {
			digits.insert(x % 10);
			x /= 10;
		}
		return digits;
	}
	// optimise shorter code
	bool CheckFriendlySequence(VI seq) {
		set<int> digits = num2set(seq.at(0));
		int sz = seq.size();
		for (int i = 1; i < sz; i++) {
			set<int> tmp_digits = num2set(seq.at(i));
			if (digits != tmp_digits)
				return false;
		}
		return true;
	}
};

#endif /* EXAMPLE10_ECLIPSE_H_ */
