#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {

	int n;
	cin >> n;

	vector<int> v(n);
	vector<int> bp(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	bp[0] = v[0];

	for (int i = 1; i < n; i++) {
		if (v[i] >= v[i - 1]) {
			bp[i] = v[i] + v[i - 1];
		}
		else {
			bp[i] = v[i];
		}
	}

	int m = *max_element(bp.begin(), bp.end());

	cout << m;

	return 0;
}
