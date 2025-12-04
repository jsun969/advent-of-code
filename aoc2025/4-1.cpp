#include <array>
#include <iostream>
#include <vector>

using namespace std;

int sol(vector<string> grid) {
	auto ROWS = grid.size(), COLS = grid[0].size();
	array<pair<int, int>, 8> DIRS = { { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 0 }, { 1, 1 } } };
	int res = 0;
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			if (grid[i][j] != '@') continue;
			int cnt = 0;
			for (auto [dx, dy] : DIRS) {
				auto x = i + dx, y = j + dy;
				if (x < 0 || x > ROWS - 1 || y < 0 || y > COLS - 1) {
					continue;
				}
				if (grid[x][y] == '@') cnt++;
			}
			if (cnt < 4) res++;
		}
	}
	return res;
}

int main() {
	string line;
	vector<string> input;

	while (true) {
		cin >> line;
		if (line == "DONE") break;
		input.push_back(line);
	}
    cout << sol(input) << endl;
	return 0;
}
