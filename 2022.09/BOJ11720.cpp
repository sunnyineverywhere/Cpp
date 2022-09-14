#include <iostream>
#include <string>
using namespace std;

int main(void) {

	int n;

	cin >> n;

	int sum = 0;
	for (int i = 0; i < n; i++) {
		int input;
		scanf_s("%1d", &input);
		sum += input;
	}

	cout << sum;
	
	return 0;
}
