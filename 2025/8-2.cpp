#include <cmath>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

using Coor = array<int, 3>;
using Dist = tuple<long long, int, int>;

long long getDist(const Coor& c1, const Coor& c2) {
	return pow(c1[0] - c2[0], 2) + pow(c1[1] - c2[1], 2) + pow(c1[2] - c2[2], 2);
}

class UnionFind {
private:
	vector<int> parents;
	vector<int> rank;

public:
	UnionFind(int size) {
		for (int i = 0; i < size; i++) {
			parents.push_back(i);
			rank.push_back(1);
		}
	}
	int find(int x) {
		while (x != parents[x]) {
			// Path compression
			parents[x] = parents[parents[x]];
			x = parents[x];
		}
		return x;
	}
	bool uni(int x, int y) {
		const auto px = find(x);
		const auto py = find(y);
		if (px == py) {
			return false;
		}
		// Union by rank
		if (rank[px] > rank[py]) {
			parents[py] = px;
		} else if (rank[px] < rank[py]) {
			parents[px] = py;
		} else {
			parents[py] = px;
			rank[px]++;
		}
		return true;
	}
};

int soln(const vector<Coor>& coors) {
	const auto N = coors.size();
	auto pqCompareDist = [](const Dist& a, const Dist& b) {
		return get<0>(a) > get<0>(b);
	};
	priority_queue<Dist, vector<Dist>, decltype(pqCompareDist)> distPQ(pqCompareDist);
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			const auto c1 = coors[i];
			const auto c2 = coors[j];
			distPQ.push(make_tuple(getDist(c1, c2), i, j));
		}
	}
	constexpr int TIMES = 1000;
	UnionFind uf(N);
	auto checkInOneGraph = [&]() {
		auto par = uf.find(0);
		for (int i = 1; i < N; i++) {
			if (uf.find(i) != par) {
				cout << "not good checking: " << i << endl;
				return false;
			}
		}
		return true;
	};
	int ans = 0;
	while (!checkInOneGraph()) {
		const auto [dist, x, y] = distPQ.top();
		distPQ.pop();
		ans = coors[x][0] * coors[y][0];
		uf.uni(x, y);
	}

	return ans;
}

int main() {
	string line;
	vector<Coor> coors;
	while (true) {
		getline(cin, line);
		if (line == "DONE") break;
		istringstream iss(line);
		string numStr;
		int i = 0;
		Coor coor;
		while (getline(iss, numStr, ',')) {
			coor[i] = stoi(numStr);
			i++;
		}
		coors.push_back(coor);
	}
	cout << soln(coors) << endl;
	return 0;
}
