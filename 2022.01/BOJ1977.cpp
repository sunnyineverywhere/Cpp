/* 백준 1977 완전제곱수 */

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(void) {
	int m;
	int n;
	cin >> m >> n;
	
	int sum = 0;
	int min = 10001;

	for (int i = 1; i <= 100; i++) {
		if (pow(i, 2) >= m && pow(i, 2) <= n) {
			sum += pow(i, 2);
		}
		if (pow(i, 2) >= m && min > pow(i, 2)) {
			min = pow(i, 2);
		}

	}
	

	if (sum == 0) {
		cout << "-1";
		return 0;
	}

	cout << sum << '\n' << min;

	return 0;
}