// GAVE UP too slow with kinda memo

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

constexpr int TRY = 99;

vector<int> strToVec(string s) {
	vector<int> res;
	for (auto ch : s) {
		res.push_back(ch - '0');
	}
	return res;
}

string vecToStr(vector<int> vec) {
	string s = "";
	for (auto v : vec) {
		s += to_string(v);
	}
	return s;
}

int soln(const vector<vector<int>>& buttons, const vector<int>& target) {
	cout << "Target: ";
	for (auto t : target) {
		cout << t << ' ';
	}
	cout << endl;

	const int N = buttons.size();

	string initKey(N, '0');
	unordered_map<string, vector<int>> dp { { initKey, target } };
	for (int i = 1; i <= TRY; i++) {
		cout << "Trying: " << i << endl;
		unordered_map<string, vector<int>> newDp;
		for (auto [k, v] : dp) {
			auto kVec = strToVec(k);
			for (int j = 0; j < N; j++) {
				auto b = buttons[j];
				auto newV = v;
				bool invalid = false;
				for (auto idx : b) {
					auto n = newV[idx] - 1;
					newV[idx] = n;
					if (n < 0) {
						invalid = true;
					}
				}
				if (invalid) continue;

				auto newKVec = kVec;
				newKVec[j]++;

				bool ok = true;
				for (auto e : newV) {
					if (e != 0) ok = false;
				}
				if (ok) return i;

				string newK = vecToStr(newKVec);
				newDp.insert({ newK, newV });

				//===== DEBUG =====
				// cout << newK << ": ";
				// for (auto e : newV) {
				// 	cout << e << ' ';
				// }
				// cout << endl;
			}
		}
		dp = newDp;
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
