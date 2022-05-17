#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int k = 1;
int arr[14];
int ans[6] = { 0 };

void bt(int s, int cnt) {
	if (cnt == 6) {
		for (int i = 0; i < 6; i++) {
			cout << ans[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = s; i < k; i++) {
		ans[cnt] = arr[i];
		bt(i + 1, cnt + 1);
	}
}

int main(void) {

	while (cin >> k && k) {

		for (int i = 0; i < k; i++) {
			cin >> arr[i];
		}

		bt(0, 0);
		cout << "\n";
	}

	return 0;
}
