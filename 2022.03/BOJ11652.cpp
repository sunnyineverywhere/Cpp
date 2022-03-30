#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long card[100001];

int main(void) {

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}

	sort(card, card + n);

	int cnt = 1; int max = 0; int res = 0;

	for (int i = 0; i < n-1; i++) {
		if (card[i] == card[i + 1]) {
			cnt++;
			if (max < cnt) {
				max = cnt;
				res = i;
			}
		}
		else {
			cnt = 1;
		}
	}

	cout << card[res];

	return 0;
}
