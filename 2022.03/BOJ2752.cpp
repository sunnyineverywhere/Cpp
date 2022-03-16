#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {

	int ar[3];
	for (int i = 0; i < 3; i++) {
		cin >> ar[i];
	}
	sort(ar, ar + 3);

	for (int i = 0; i < 3; i++) {
		cout << ar[i] << " ";
	}
}
