#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		int sum = a + b;
		cout << sum << '\n';
	}

	return 0;
