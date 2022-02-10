/*
m부터 n까지 체를 이용하여 소수를 거른다
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void) {

	long long m, n;
	cin >> m >> n;

	vector<long long> primeNumber(n+1, 1);

	for (int i = 0; i <= n; i++) { // 여기 등호 안 써서 계속 틀림
		primeNumber[i] = i;
	}

	for (long long i = 2; i <= sqrt(n); i++) {
		if (primeNumber[i] == i) {
			for (long long j = i * 2; j <= n; j += i) {
				
				if (primeNumber[j] == j) {
					primeNumber[j] = i;
				}
			}
		}
	}

	for (long long i = m; i <= n; i++) {
		if (i == 0 || i == 1) {
			continue;
		}
		if (primeNumber[i] == i) {
			cout << i << '\n';
		}
	}

	return 0;
}
