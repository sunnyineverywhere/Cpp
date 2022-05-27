#include <iostream>
#include <vector>
using namespace std;

int main(void) {

	int x;
	cin >> x;

	vector<int> dp(x + 1);
	vector<int> num(x + 1);

	dp[1] = 0;

	for (int i = 2; i <= x; i++) {
		dp[i] = dp[i - 1] + 1;
		num[i] = i - 1;

		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
			dp[i] = dp[i / 3] + 1;
			num[i] = i / 3;
		}

		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
			dp[i] = dp[i / 2] + 1;
			num[i] = i / 2;
		}
	}

	cout << dp[x] << '\n';

	while (x != 0) {
		cout << x << ' ';
		x = num[x];
	}

	return 0;
}
