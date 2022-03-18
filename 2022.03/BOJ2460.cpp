#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	vector<pair<int, int>> t(10, { 0, 0 });

	int max = 0;
	int cnt = 0;
	for (int i = 0; i < 10; i++) {
		cin >> t[i].first >> t[i].second;
		cnt = cnt + t[i].second - t[i].first;
		if (max < cnt) {
			max = cnt;
		}
	}

	cout << max;

}
