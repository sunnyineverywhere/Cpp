#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int a[100010];

int solve(int input) {
	int start = 0;
	int end = n - 1;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (a[mid] == input) {
			return 1;
		}
		else if (input < a[mid]) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return 0;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	cin >> m;
	for (int i = 0; i < m; i++) {
		int input;
		cin >> input;
		cout << solve(input) << '\n';
	}

	return 0;
}
