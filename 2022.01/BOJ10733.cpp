#include <iostream>
#include <stack>

using namespace std;

int main(void) {

	int k;
	cin >> k;
	stack<int> s;

	int size = 0;

	while (k--) {
		int input;
		cin >> input;
		if (input != 0) {
			s.push(input);
			size++;
		}
		else {
			s.pop();
			size--;
		}
	}

	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += s.top();
		s.pop();
	}

	cout << sum;

	return 0;
}
