/* 백준 1065 한수 */

#include <iostream>
using namespace std;

int number(int n) {
	if (n < 100) {
		return true;
	}
	else {
		int a = n % 10; // 1의 자리 수
		n /= 10;
		int b = n % 10; // 10의 자리 수
		int c = n / 10; // 100의 자리 수

		if (b - a == c - b) {
			return true;
		}
		else
			return false;
	}
}

int main(void) {

	int cnt = 0;
	int t;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		if (number(i)) {
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}