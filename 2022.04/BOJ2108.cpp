#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
int num[8001] = { 0, };

int main(void) {
	cin >> n;

	vector<int> v(n);
	double sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
		num[v[i] + 4000]++;
	}

	// mean
	int avg = round((double)sum / (double)n);
	cout << avg << "\n";

	sort(v.begin(), v.end());

	// middle
	cout << v[n / 2] << "\n";

	// most
	
	int cnt = 0;
	int idx;
	for (int i = 0; i < 8001; i++) {
		if (num[i] > cnt) {
			cnt = num[i];
			idx = i;
		}
	}

	for (int i = idx + 1; i < 8001; i++) {
		if (num[i] == cnt) {
			idx = i;
			break;
		}
	}

	cout << idx - 4000 << '\n';

	// range
	cout << v[n-1] - v[0];

	return 0;
}
