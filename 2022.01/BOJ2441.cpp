/* 백준 2441번 별 찍기 - 4 */

#include <iostream>
using namespace std;

int main(void) {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			cout << " ";
		}
		for (int k = 0; k <= n - i; k++) {
			cout << "*";
		}
		cout << "\n";
	}

	return 0;
}