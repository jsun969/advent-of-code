#include <bits/stdc++.h>

using namespace std;

int soln(unordered_map<string, vector<string>> adjList) {
	int res = 0;
	unordered_set<string> visited;
	function<void(string)> dfs = [&](string cur) -> void {
		if (visited.contains(cur)) return;
		if (cur == "out") {
			res++;
			return;
		}
		auto conn = adjList[cur];
		for (auto c : conn) {
			visited.insert(cur);
			dfs(c);
			visited.erase(cur);
		}
	};
	dfs("you");
	return res;
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
