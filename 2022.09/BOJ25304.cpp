#include <iostream>
using namespace std;
int x, n, a, b;

int main(void) {
	cin >> x;
	cin >> n;

	int res = 0;

	while (n--) {
		cin >> a >> b;
		res += a * b;
	}

	if (res == x) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}

	return 0;
}
