#include <iostream>
#include <vector>
using namespace std;

vector<bool> pn(1000001, true);

void Eratos() {
	pn[0] = false;
	pn[1] = false;
	pn[2] = false;

	for (int i = 2; i*i <= 1000000; i++) {
		if (pn[i]) {
			for (int j = i * i; j <= 1000000; j += i) {
				pn[j] = false;
			}
		}
	}
}

int main(void) {
	int n = 1;
	while (n != 0) {
		cin >> n;
		int left = 3;
		int right = n - 3;
		while (left <= right) {
			if (pn[left] && pn[right]) {
				break;
			}
			left += 2;
			right -= 2;
		}
		if (left > right) {
			cout << "Goldbach's conjecture is wrong.";
		}
		else {
			cout << n << " = " << left << " + " << right;
		}
	}

	return 0;
}
