#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
	return a > b;
}


int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	int n = 2;

	while (t--) {

		vector<int> list(10);
		for (int i = 0; i < 10; i++) {
			cin >> list[i];
		}

		sort(list.begin(), list.end(), compare);
		cout << list[n] << '\n';

	}



	return 0;
}
