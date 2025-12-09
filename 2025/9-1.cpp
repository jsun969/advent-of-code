#include <bits/stdc++.h>

using namespace std;

long long soln(const vector<array<int, 2>>& coors) {
	// iterate thru each pair
	// area = (abs(x1 - x2) + 1) * (abs(y1 - y2) + 1)
    long long maxArea = numeric_limits<long long>::min();
	const int N = coors.size();
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			auto a = coors[i];
			auto b = coors[j];
			long long area = static_cast<long long>(abs(a[0] - b[0]) + 1) * static_cast<long long>(abs(a[1] - b[1]) + 1);
			cout << "A: " << a[0] << ' ' << a[1] << endl;
			cout << "B: " << b[0] << ' ' << b[1] << endl;
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
		coors.push_back(coor);
	}
	cout << soln(coors) << endl;
	return 0;
}
