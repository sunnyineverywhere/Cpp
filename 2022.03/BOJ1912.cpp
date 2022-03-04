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
		bp[i] = max(bp[i - 1] + v[i], v[i]);
	}

	/*
	for (int i = 0; i < n; i++) {
		cout << bp[i] << " ";
	}	
		cout << "\n";
	*/
	



	int m = *max_element(bp.begin(), bp.end());

	cout << m;

	return 0;
}
