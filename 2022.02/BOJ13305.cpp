#include <iostream>
#include <vector>
using namespace std;

int main(void) {

	long long n;
	cin >> n;

	vector<long long> city(n + 1); // 도시 당 주유소 가격
	vector<long long> highway(n+1); // 고속도로 길이

	for (int i = 1; i <= n - 1; i++) {
		cin >> highway[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> city[i];
	}

	long long cost = 0;
	long long minimum = city[1];

	for (long long i = 1; i <= n; i++) {
		if (city[i] < minimum) {
			minimum = city[i];
		}
		cost += minimum * highway[i];
	}

	cout << cost;

	return 0;
}
