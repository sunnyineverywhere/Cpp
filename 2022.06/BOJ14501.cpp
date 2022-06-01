#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int before[16] = { 0 };
int dp[16] = { 0 };

int n;

vector<pair<int, int>> tp(16);

int main(void) {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> tp[i].first >> tp[i].second;
		dp[i] = tp[i].second;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (i - j >= tp[j].first) {
				dp[i] = max(tp[i].second + dp[j], dp[i]);
			}
		}
	}

	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (i + tp[i].first <= n + 1) {
			if (res < dp[i]) {
				res = dp[i];
			}
		}
	}

	cout << res;

	return 0;
}
