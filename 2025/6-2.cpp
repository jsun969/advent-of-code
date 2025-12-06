#include <cctype>
#include <iostream>
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

long long soln(vector<string> lines) {
	const auto ROWS = lines.size(), COLS = lines[0].size();
	cout << ROWS << ' ' << COLS << endl;
	string num;
	vector<long long> nums;
	long long res = 0;
	for (int i = COLS - 1; i >= 0; i--) {
		for (int j = 0; j < ROWS; j++) {
			auto ch = lines[j][i];
			if (isdigit(ch)) {
				num += ch;
			} else if (ch == ' ' && num != "") {
				nums.push_back(stoll(num));
				num = "";
			} else if (ch == '+' || ch == '*') {
				if (num != "") {
					nums.push_back(stoll(num));
					num = "";
				}
				for (auto n : nums) {
					cout << n << ' ';
				}
				cout << ch << endl;
				res += calc(nums, ch);
				nums.clear();
			}
		}
	}
	return res;
}

int main() {
	string line;
	vector<string> lines;
	while (true) {
		getline(cin, line);
		if (line == "DONE") break;
		lines.push_back(line);
	}
	cout << "OUTPUT" << endl;
	cout << soln(lines) << endl;
	return 0;
}
