#include <iostream>
#include <string>
#include <vector>
using namespace std;

int soln(vector<string> g) {
	const auto ROWS = g.size(), COLS = g[0].size();
	int res = 0;
	for (int i = 1; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			if (g[i][j] == '^' && g[i - 1][j] == '|') {
				g[i][j - 1] = '|';
				g[i][j + 1] = '|';
				res++;
			} else if (g[i - 1][j] == 'S' || g[i - 1][j] == '|') {
				g[i][j] = '|';
			}
		}
		cout << g[i] << endl;
	}
	return res;
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
