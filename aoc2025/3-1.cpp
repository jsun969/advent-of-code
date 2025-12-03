#include <iostream>
#include <string>
#include <vector>

using namespace std;

int maxJoltage(string bank) {
	auto LEN = bank.length();
	vector<int> maxAft;
	maxAft.resize(LEN);
    maxAft[LEN - 1] = 0;
	for (int i = LEN - 2; i >= 0; i--) {
		maxAft[i] = max(bank[i + 1] - '0', maxAft[i + 1]);
	}
    int ans = 0;
    for (int i = 0; i < LEN - 1; i++) {
        auto cur = (bank[i] - '0') * 10 + maxAft[i];
        ans = max(ans, cur);
    }
	return ans;
}

int main() {
	int res = 0;
    string battery;
    while (true) {
        cin >> battery;
        res += maxJoltage(battery);
        cout << res << endl;
    }
	return 0;
}
