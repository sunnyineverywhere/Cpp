#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main(void) {

	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++){
		cin >> v[i];
	}

	sort(v.begin(), v.end(), greater<int>());

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		long long sum = v[i] * (i + 1);
		if (sum > ans) {
			ans = sum;
		}
	}

	cout << ans;

	return 0;
}
