#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int a, b, c;

	cin >> a >> b >> c;
	int res;

	if (a == b && b == c) {
		res = 10000 + a * 1000;
	}
	else if ((a == b && a != c)) {
		res = a * 100 + 1000;		
	}
	else if ((a == c && b != c)) {
		res = a * 100 + 1000;
	}
	else if (b == c && a != c) {
		res = b * 100 + 1000;
	}
	else {
		int max = a;
		if (max < b) {
			max = b;
		}
		if (max < c) {
			max = c;
		}
		res = 100 * max;
	}


	cout << res;

	return 0;
}
