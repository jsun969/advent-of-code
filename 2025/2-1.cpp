#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solve(vector<tuple<string, string>> ranges) {
    long long ans = 0;
    for (auto [stStr, endStr] : ranges) {
        auto st = stoll(stStr);
        auto end = stoll(endStr);
        for (auto i = st; i <= end; i++) {
            auto cur = to_string(i);
            auto curLen = cur.length();
            if (curLen % 2 != 0) continue;
            auto half1 = cur.substr(0, curLen / 2);
            auto half2 = cur.substr(curLen / 2, curLen / 2);
            if (half1 != half2) continue;
            ans += stoll(cur);
        }
    }
    return ans;
}

int main() {
	string input;
	cin >> input;
	cout << endl << "=== OUTPUT ===" << endl;

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
