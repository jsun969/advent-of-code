#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool checkValidNum(string num) {
	const auto LEN = num.length();
	for (int len = 1; len <= LEN / 2; len++) {
		auto first = num.substr(0, len);
        bool isValid = true;
		for (int st = len; st <= LEN - 1; st += len) {
			auto w = num.substr(st, len);
			if (w != first) {
                // cout << "first: " << first << " window: " << w << endl;
                isValid = false;
				break;
			}
		}
        if (isValid) {
            return true;
        }
	}
	return false;
}

long long solve(vector<tuple<string, string>> ranges) {
	long long ans = 0;
	for (auto [stStr, endStr] : ranges) {
		auto st = stoll(stStr);
		auto end = stoll(endStr);
		for (auto i = st; i <= end; i++) {
			auto cur = to_string(i);
			if (!checkValidNum(cur)) continue;
			cout << "cur: " << cur << endl;
			ans += stoll(cur);
		}
	}
	return ans;
}

int main() {
	string input;
	cin >> input;
	cout << endl
			 << "=== OUTPUT ===" << endl;

	vector<tuple<string, string>> ranges;
	string stStr, endStr;
	bool processSt = true;
	for (auto ch : input) {
		if (ch == ',') {
			ranges.emplace_back(make_pair(stStr, endStr));
			stStr = "";
			endStr = "";
			processSt = true;
			continue;
		}
		if (ch == '-') {
			processSt = false;
			continue;
		}
		if (processSt) {
			stStr += ch;
		} else {
			endStr += ch;
		}
	}
	ranges.emplace_back(make_pair(stStr, endStr));
	cout << solve(ranges) << endl;
	return 0;
}
