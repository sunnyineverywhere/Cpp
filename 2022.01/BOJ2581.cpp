#include <iostream>
#include <vector>
using namespace std;

int main(void) {

	/*
	clock_t start, end;
	double result;
	*/
	

	int m, n;
	cin >> m >> n;

	int min = 0;
	int sum = 0;

	// start = clock();

	for (int i = m; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j < i; j++) {
			if (i % j == 0) {
				cnt++;
			}
		}
		if (cnt == 1) {
			sum += i;
			if (min == 0) {
				min = i;
			}
		}
	}

	if (sum != 0) {
		cout << sum << "\n" << min;
	}
	else {
		cout << "-1";
	}

	/* 
	end = clock();

	result = (double)(end - start);
	cout << result;
	*/

	return 0;
}
