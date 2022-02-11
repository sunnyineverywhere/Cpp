#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main(void) {

	int input;
	cin >> input;

	vector<int> n;

	int size = 0 ;

	while (input > 0) {
		n.push_back(input % 10);
		input /= 10;
		size++;
	}

	sort(n.begin(), n.end(), compare);

	for (int i = 0; i < size; i++) {
		cout << n[i];
	}

	return 0;
}
