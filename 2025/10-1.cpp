#include <bits/stdc++.h>

using namespace std;

// Turn button to binary num
// use XOR to toggle from 0
// dfs and assume each button can only be toggled once

int getLightBinNum(const string& light) {
	// . -> 0, # -> 1
	string binStr;
	for (auto ch : light) {
		binStr += (ch == '.' ? '0' : '1');
	}
	return stoi(binStr, nullptr, 2);
}
void TEST_getLightBinNum() {
	auto res = getLightBinNum(".#.#.");
	cout << bitset<5>(res) << endl;
}

int getButtonBinNum(const vector<int>& button, int size) {
	string binStr(size, '0');
	for (auto i : button) {
		binStr[i] = '1';
	}
	return stoi(binStr, nullptr, 2);
}
void TEST_getButtonBinNum() {
	auto res = getButtonBinNum({ 0, 2, 3, 4 }, 5);
	cout << bitset<5>(res) << endl;
}

int soln(const string& light, const vector<vector<int>>& buttons) {
	const int LEN = light.length();
	const int N = buttons.size();

	auto lightBin = getLightBinNum(light);
	vector<int> buttonBin;
	for (auto b : buttons) {
		buttonBin.push_back(getButtonBinNum(b, LEN));
	}

	function<bool(int, int, int)> dfs = [&](int idx, int cnt, int cur) -> bool {
		if (cnt == 0) return cur == lightBin;
		bool res = false;
		for (int i = 0; i < N; i++) {
			res = dfs(i, cnt - 1, cur ^ buttonBin[i]) || res;
		}
		return res;
	};

	for (int i = 1; i <= 999; i++) {
		if (dfs(0, i, 0)) {
			return i;
		}
	}
	return -1;
}

int main() {
	// TEST_getLightBinNum();
	// TEST_getButtonBinNum();
	// cout << soln(".##.", { { 3 }, { 1, 3 }, { 2 }, { 2, 3 }, { 0, 2 }, { 0, 1 } }) << endl;
	// cout << soln("...#.", { { 0, 2, 3, 4 }, { 2, 3 }, { 0, 4 }, { 0, 1, 2 }, { 1, 2, 3, 4 } }) << endl;
	string s;
	int res = 0;
	string light;
	vector<vector<int>> buttons;

	while (true) {
		cin >> s;
		if (s == "DONE") break;

		if (s[0] == '[') {
			light = s.substr(1, s.length() - 2);
		} else if (s[0] == '(') {
			string token;
			vector<int> btn;
			for (auto ch : s) {
				if (ch == ',' || ch == ')') {
					btn.push_back(stoi(token));
					token = "";
				} else if (isdigit(ch)) {
					token += ch;
				}
			}
			buttons.push_back(btn);
		} else if (s[0] == '{') {
			auto cur = soln(light, buttons);
			cout << cur << endl;
			res += cur;
			light = "";
			buttons.clear();
		}
	}
	cout << "RES: " << res << endl;
	return 0;
}
