#include <iostream>
#include <string>
#include <map>
using namespace std;

int n, m; // n은 a 집합 원소의 개수, m은 b 집합 원소의 개수

int main(void) {

	cin >> n >> m;

	map<int, bool> A;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		A.insert({ a, true });
	}

	int cnt = 0;
	for (int i = 0; i < m; i++) {
		int b;
		cin >> b;
		if (A[b]) {
			cnt++;
			n--;
		}
	}

	cout << m + n - cnt;

	return 0;
}
