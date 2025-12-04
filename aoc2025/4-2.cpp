#include <array>
#include <iostream>
#include <vector>

using namespace std;

int lift(vector<vector<char>>& grid) {
	auto ROWS = grid.size(), COLS = grid[0].size();
	array<pair<int, int>, 8> DIRS = { { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 0 }, { 1, 1 } } };
	int res = 0;
	vector<pair<int, int>> lifted;
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
			if (cnt < 4) {
				lifted.push_back({ i, j });
				res++;
			}
		}
	}
	for (auto [i, j] : lifted) {
		grid[i][j] = 'x';
	}
	return res;
}

int liftLoop(vector<vector<char>>& grid) {
	int cur = -1, res = 0;
	while (cur != 0) {
		cur = lift(grid);
		cout << cur << endl;
		res += cur;
	}
	return res;
}

int main() {
	string line;
	vector<vector<char>> input;

	while (true) {
		cin >> line;
		if (line == "DONE") break;
		vector<char> lineVec(line.begin(), line.end());
		input.push_back(lineVec);
	}
	cout << "ANS: " << liftLoop(input) << endl;
	return 0;
}
