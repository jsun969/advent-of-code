#include <bits/stdc++.h>

using namespace std;

constexpr string A = "svr";
constexpr string B = "fft";
constexpr string C = "dac";
constexpr string D = "out";
// A -> B -> C -> D
// A -> C -> B -> D

long long soln(unordered_map<string, vector<string>> adjList) {
	unordered_map<string, int> indeg;
	unordered_map<string, long long> ways;
	for (auto [p, co] : adjList) {
		for (auto c : co) {
			++indeg[c];
		}
	}
	deque<string> lv;
	lv.push_back(A);
	ways[A] = 1;
	while (!lv.empty()) {
		const auto len = lv.size();
		// check if this level has B or C
		// if does, remove ways for rest ele
		bool removeRestWays = false;
		for (auto e : lv) {
			if (e == B || e == C) {
				removeRestWays = true;
			}
		}
		if (removeRestWays) {
			for (auto e : lv) {
				if (e == B || e == C) continue;
				ways[e] = 0;
			}
		}
		for (int i = 0; i < len; ++i) {
			auto cur = lv.front();
			lv.pop_front();
			cout << cur << ' ' << ways[cur] << ' ';
			for (auto co : adjList[cur]) {
				ways[co] += ways[cur];
				auto ind = --indeg[co];
				if (ind == 0) {
					lv.push_back(co);
				}
			}
		}
		cout << endl;
	}
	return ways[D];
}

int main() {
	string s;
	unordered_map<string, vector<string>> adjList;
	vector<string> conn;
	string cur;
	bool firstKey = true;
	while (true) {
		cin >> s;
		if (s == "DONE") {
			adjList.insert({ cur, conn });
			break;
		}
		if (s.back() == ':') {
			// push the prev one
			if (!firstKey) {
				adjList.insert({ cur, conn });
				conn.clear();
			} else {
				firstKey = false;
			}
			// create new one
			cur = s.substr(0, s.length() - 1);
		} else {
			conn.push_back(s);
		}
	}
	// ===== DEBUG =====
	// for (auto [k, v] : adjList) {
	//     cout << k << " HAS: ";
	//     for (auto vv : v) {
	//         cout << vv << ", ";
	//     }
	//     cout << endl;
	// }
	cout << soln(adjList) << endl;
	return 0;
}
