#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int t;

long long dp[1000002];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;

	for (int i = 1; i <= 1000001; i++) {
		for (int j = i; j <= 1000001; j += i) {
			dp[j] += i;
		}
	}

	for (int i = 2; i <= 1000001; i++) {
		dp[i] += dp[i - 1];
	}

	while (t--) {
		int input;
		cin >> input;
		cout << dp[input] << "\n";
	}

	return 0;
}
