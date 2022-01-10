/* 백준 1978 소수 찾기*/
/* 엥...? 이게 어떻게 한 번에 맞았지...? */


#include <iostream>
using namespace std;

int main(void) {
	int num[100] = { 0 };

	int n;
	cin >> n;
	int out = 0;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		int cnt = 0;
		for (int j = 1; j <= num[i]; j++) {
			if (num[i] % j == 0) {
				cnt++;
			}
		}
		if (cnt == 2) {
			out++;
		}
	}

	cout << out;

	return 0;
}