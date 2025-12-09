// GAVE UP

#include <bits/stdc++.h>

using namespace std;

// check if a point is in area
// make a ray to right
// if gets odd points: inside, if gets even: outside

array<array<int, 2>, 4> findRectVertex(array<int, 2> p1, array<int, 2> p2) {
	return { p1, p2, { p1[0], p2[1] }, { p2[0], p1[1] } };
}

long long soln(const vector<array<int, 2>>& coors) {
	const int N = coors.size();
	// Ray casting algo
	auto checkVertexInShape = [&](array<int, 2> v) -> bool {
		bool inside = false;
		auto [vx, vy] = v;
		for (int i = 0; i < N; i++) {
			auto [x1, y1] = coors[i];
			auto [x2, y2] = i != N - 1 ? coors[i + 1] : coors[0];

			if (x1 == x2) {
				int minY = min(y1, y2);
				int maxY = max(y1, y2);
				if (vx == x1) {
					if (minY <= vy && vy <= maxY) {
						return true;
					}
				}
				if (vy >= minY && vy < maxY && vx < x1) {
					inside = !inside;
				}
			} else if (y1 == y2) {
				if (vy == y1) {
					int minX = min(x1, x2);
					int maxX = max(x1, x2);
					if (minX <= vx && vx <= maxX) {
						return true;
					}
				}
			}
		}
		return inside;
	};
	// DEBUG TEST checkVertexInShape
	// for (int i = 0; i < 9; i++) {
	// 	for (int j = 0; j < 14; j++) {
	// 		cout << (checkVertexInShape({ i, j }) ? '#' : '.');
	// 	}
	// 	cout << endl;
	// }

	// For each rect find 4 vertices
	long long maxArea = numeric_limits<long long>::min();
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			auto a = coors[i];
			auto b = coors[j];
			auto rv = findRectVertex(a, b);

			bool inShape = true;
			for (const auto& v : rv) {
				if (!checkVertexInShape(v)) {
					inShape = false;
					break;
				}
			}
			if (!inShape) continue;

			long long area = static_cast<long long>(abs(a[0] - b[0]) + 1) * static_cast<long long>(abs(a[1] - b[1]) + 1);
			cout << "Area: " << area << endl;
			maxArea = max(maxArea, area);
		}
	}
	return maxArea;
}

int main() {
	string line;
	vector<array<int, 2>> coors;
	while (true) {
		getline(cin, line);
		if (line == "DONE") break;
		istringstream iss(line);
		string numStr;
		int i = 0;
		array<int, 2> coor;
		while (getline(iss, numStr, ',')) {
			coor[i] = stoi(numStr);
			i++;
		}
		swap(coor[0], coor[1]);
		coors.push_back(coor);
	}
	cout << soln(coors) << endl;
	return 0;
}
