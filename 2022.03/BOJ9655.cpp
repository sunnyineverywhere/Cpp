#include <iostream>
#include <vector>
using namespace std;

int n;
int cnt = 0;

int main(void) {

	cin >> n;

	while (n > 0) {
		if (n > 3) {
			cnt++;
			n -= 3;
		}
		else {
			cnt++;
			n -= 1;
		}
	}

	if (cnt % 2 == 0) {
		cout << "CY";
	}
	else {
		cout << "SK";
	}

	return 0;
}
