#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string sol(string bank) {
	auto findMaxIdx = [&bank](int st, int end) -> int {
		int maxd = -1, res = -1;
		for (int i = st; i <= end; i++) {
			auto curd = bank[i] - '0';
			if (curd > maxd) {
				maxd = curd;
				res = i;
			}
		}
		return res;
	};
	const int RES_LEN = 12;
	int lastMax = -1;
	string res;
	for (int r = RES_LEN - 1; r >= 0; r--) {
		auto nextMax = findMaxIdx(lastMax + 1, bank.length() - r - 1);
		cout << lastMax << ' ' << bank.length() - r - 1 << ' ' << nextMax << endl;
		res += bank[nextMax];
		lastMax = nextMax;
	}
	return res;
}

int main() {
	long long res = 0;
	string battery;
	while (true) {
		cin >> battery;
		res += stoll(sol(battery));
		cout << "RES: " << res << endl;
	}
	return 0;
}
