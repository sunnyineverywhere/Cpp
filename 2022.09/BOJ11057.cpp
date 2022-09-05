#include <iostream>
#include <vector>
#define MOD 10007
using namespace std;


int dp[1002][10] = { 0, };

int solve(int n) {

	// 
	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 10; j++) {
			if (j == 0) {
				dp[i][0] = 1;
				continue;
			}
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			dp[i][j] %= MOD;
		}
	}

	int res = 0;
	for (int i = 0; i < 10; i++) {
		res = (res + dp[n][i]);
	}
	return res % MOD;
}

int main(void) {
	int n;
	cin >> n;
	cout << solve(n);
	return 0;
}
