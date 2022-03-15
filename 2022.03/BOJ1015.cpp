#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	
	int n;
	cin >> n;

	pair<int, int> p[50];

	for (int i = 0; i < n; i++) {
		cin >> p[i].first;
		p[i].second = i;
	}

	sort(p, p + n);

	vector<int> v(50);
	for (int i = 0; i < n; i++) {
		v[p[i].second] = i;
	}

	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}

	
	return 0;
}
