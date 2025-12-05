#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long soln(vector<pair<long long, long long>> ranges) {
	sort(ranges.begin(), ranges.end());
	long long res = 0;
	auto far = ranges[0];
	res += ranges[0].second - ranges[0].first + 1;
	for (auto cur : ranges) {
		auto [st, end] = cur;
		auto [fst, fend] = far;
		cout << "cur: " << st << " - " << end << endl;
		cout << "far: " << fst << " - " << fend << endl;
		if (fend >= end) continue;
		if (fend < st) {
			res += end - st + 1;
		} else if (fend < end) {
			res += end - fend;
		}
		cout << "res: " << res << endl << endl;
		far = cur;
	}
	return res;
}

pair<long long, long long> processRangeStr(string str) {
	bool processSt = true;
	string stS, endS;
	for (auto ch : str) {
		if (ch == '-')
			processSt = false;
		else if (processSt) {
			stS += ch;
		} else {
			endS += ch;
		}
	}
	return make_pair(stol(stS), stol(endS));
}

int main() {
	string line;
	vector<pair<long long, long long>> ranges;
	while (true) {
		cin >> line;
		if (line == "DONE") {
			break;
		}
		ranges.push_back(processRangeStr(line));
	}
	cout << soln(ranges) << endl;
	return 0;
}
