#include <iostream>
#include <vector>

using namespace std;

int soln(vector<pair<long long, long long>> ranges, vector<long long> ids) {
	int res = 0;
	for (auto id : ids) {
        for (auto [st, end] : ranges) {
            if (st <= id && id <= end) {
                res++;
                break;
            }
        }
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
	bool readRange = true;
	vector<pair<long long, long long>> ranges;
	vector<long long> ids;
	while (true) {
		cin >> line;
		if (line == "ID") {
			readRange = false;
			continue;
		}
		if (line == "DONE") {
			break;
		}
		if (readRange) {
			ranges.push_back(processRangeStr(line));
		} else {
			ids.push_back(stol(line));
		}
	}
	cout << soln(ranges, ids) << endl;
	return 0;
}
