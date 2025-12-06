#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

long long calc(vector<long long> nums, char op) {
	long long ans;
	if (op == '+') {
		ans = 0;
		for (auto n : nums) {
			ans += n;
		}
	} else {
		ans = 1;
		for (auto n : nums) {
			ans *= n;
		}
	}
	return ans;
}

long long soln(vector<vector<long long>> nums, vector<char> ops) {
	const auto ROWS = nums.size(), COLS = nums[0].size();
	long long res = 0;
	for (auto i = 0; i < COLS; i++) {
		vector<long long> cur;
		for (auto j = 0; j < ROWS; j++) {
			cur.push_back(nums[j][i]);
		}
		res += calc(cur, ops[i]);
	}
	return res;
}

int main() {
	string line;
	vector<vector<long long>> nums;
	vector<char> ops;
	while (true) {
		getline(cin, line);
		if (line == "DONE") break;
		if (line[0] == '+' || line[0] == '*') {
			istringstream iss(line);
			char op;
			while (iss >> op) {
				ops.push_back(op);
			}
			continue;
		}
		// str to int vec
		vector<long long> lineNums;
		istringstream iss(line);
		long long num;
		while (iss >> num) {
			lineNums.push_back(num);
		}
		cout << endl;
		nums.push_back(lineNums);
	}
	cout << "OUTPUT" << endl;
	cout << soln(nums, ops) << endl;
	return 0;
}
