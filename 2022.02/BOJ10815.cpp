#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int x, int y) {
	return x < y;
}

int main(void) {

	int n, m;
	cin >> n;
	vector<int> v1(n);
	for (int i = 0; i < n; i++) {
		cin >> v1[i];
	}
	cin >> m;
	vector<int> v2(m);
	for (int i = 0; i < m; i++) {
		cin >> v2[i];
	}

	vector<int> v3(m, 0);

	sort(v1.begin(), v1.end(), compare);

	for (int i = 0; i < m; i++) {
		int left = 0;
		int right = n-1;		  
		while (left <= right) {
			int mid = (left + right) / 2;
			if (v1[mid] == v2[i]) {
				v3[i] = 1;
				break;
			}
			else if (v1[mid] > v2[i]) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		cout << v3[i] << " ";
	}

	return 0;
}
