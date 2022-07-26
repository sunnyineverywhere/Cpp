#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {

	int n;
	cin >> n;
	vector<int> hills(n);
	vector<bool> check(n);

	for (int i = 0; i < n; i++) {
		cin >> hills[i];
	}

	sort(hills.begin(), hills.end());

	int ans = 99999999;
	for (int i = 0; i < n; i++) {
		int tmp = 0;
		for (int j = 0; j < n; j++) {
			if (hills[j] < i) {
				tmp += (i - hills[j]) * (i - hills[j]);
			}
			if (hills[j] > i + 17) {
				tmp += (hills[j] - i - 17) * (hills[j] - i - 17);
			}
		}
		ans = min(ans, tmp);
		// cout << tmp << "\n";
	}
	
	cout << ans;

	return 0;
}
