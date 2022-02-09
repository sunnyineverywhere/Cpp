#include <iostream>
using namespace std;

// f(y) == 모든 약수를 더한 값
// y <= x
// g(x) == 모든 f(y)의 합

// 1 -> 1
// 2- > 1, 1, 2
// 4-> 1, 1, 2, 1, 3, 1, 2, 4
// 10 ->

int main(void) {

	int n;
	cin >> n;

	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += (n / i) * i;
	}

	cout << sum;

	return 0;
}
