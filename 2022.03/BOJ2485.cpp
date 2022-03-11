#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Euc(int x, int y) {
	int r = x % y;
	if (r == 0) {
		return y;
	}
	else {
		return Euc(y, r);
	}
}

int main(void) {

	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> t(n);


	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	for (int i = 1; i < n; i++) {
		t[i - 1] = v[i] - v[i - 1];
	}

	int gcd = t[0];
	for (int i = 1; i < n - 1; i++) {
		gcd = Euc(gcd, t[i]);
	}

	int cnt = 0;
	for (int i = 0; i < n - 1; i++) {
		cnt += (t[i] / gcd) - 1;
	}

	cout << cnt;

}
