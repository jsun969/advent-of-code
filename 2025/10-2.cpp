// WIP brute force TLE

#include <bits/stdc++.h>

using namespace std;

constexpr int TRY = 99999;

int soln(const vector<vector<int>>& buttons, const vector<int>& target) {
	cout << "Target: ";
	for (auto t : target) {
		cout << t << ' ';
	}
	cout << endl;

	const int LEN = target.size();
	const int N = buttons.size();

	function<bool(int, int, vector<int>)> dfs = [&](int idx, int cnt, vector<int> cur) -> bool {
		for (auto n : cur) {
			if (n < 0) return false;
		}
		if (cnt == 0) {
			for (auto n : cur) {
				if (n != 0) return false;
			}
			return true;
		}
		for (auto ix : buttons[idx]) {
			cur[ix]--;
		}
		bool res = false;
		for (int i = 0; i < N; i++) {
			res = dfs(i, cnt - 1, cur) || res;
		}
		return res;
	};

	for (int i = 1; i <= TRY; i++) {
		cout << "Trying: " << i << endl;
		if (dfs(0, i, target)) {
			return i;
		}
	}
	return -1;
}

int main() {
	// cout << soln({ { 3 }, { 1, 3 }, { 2 }, { 2, 3 }, { 0, 2 }, { 0, 1 } }, { 3, 5, 4, 7 }) << endl;
	// cout << soln({ { 0, 2, 3, 4 }, { 2, 3 }, { 0, 4 }, { 0, 1, 2 }, { 1, 2, 3, 4 } }, { 7, 5, 12, 7, 2 }) << endl;

	string s;
	int res = 0;
	vector<vector<int>> buttons;
	vector<int> target;

	while (true) {
		cin >> s;
		if (s == "DONE") break;

		if (s[0] == '[') {
			continue;
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
			string token;
			for (auto ch : s) {
				if (ch == ',' || ch == '}') {
					target.push_back(stoi(token));
					token = "";
				} else if (isdigit(ch)) {
					token += ch;
				}
			}

			auto cur = soln(buttons, target);
			cout << cur << endl;
			res += cur;
			target.clear();
			buttons.clear();
		}
	}
	cout << "RES: " << res << endl;
	return 0;
}
