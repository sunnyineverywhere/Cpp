#include <iostream>
#include <vector>
using namespace std;

vector<int> pn(1000001, 0);

void Eratos() {

}

int main(void) {

	pn[0] = 1;
	pn[1] = 1;
	pn[2] = 1;

	for (int i = 2; i * i <= 1000000; i++) {
		if (pn[i] == 0) {
			for (int j = i * i; j <= 1000000; j += i) {
				pn[j] = 1;
			}
		}
	}

	int n;
	while (1) {
		cin >> n;
		int left = 3;
		int right = n - 3;
		while (left <= right) {
			if (!pn[left] && !pn[right]) {
				if (left + right == n) {
					break;
				}
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
