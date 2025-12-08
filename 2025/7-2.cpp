#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

long long soln(vector<string> g) {
	const auto ROWS = g.size(), COLS = g[0].size();

	map<pair<int, int>, long long> memo;
	function<long long(int x, int y)> helper = [&](int x, int y) -> long long {
		if (x == ROWS - 1) return 1;
		if (memo.find({ x, y }) != memo.end()) {
			auto res = memo.at({ x, y });
			return res;
		}
		if (g[x][y] == '^') {
			auto res = helper(x + 1, y - 1) + helper(x + 1, y + 1);
			memo[{ x, y }] = res;
			return res;
		} else {
			auto res = helper(x + 1, y);
			memo[{ x, y }] = res;
			return res;
		}
	};

	int startY;
	for (int i = 0; i < COLS; i++) {
		if (g[0][i] == 'S') {
			startY = i;
			break;
		}
	}

	return helper(1, startY);
}

int main() {
	string line;
	vector<string> graph;
	while (true) {
		getline(cin, line);
		if (line == "DONE") break;
		graph.push_back(line);
	}
	cout << "OUTPUT" << endl;
	cout << soln(graph) << endl;
	return 0;
}
