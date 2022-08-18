#include <iostream>
#include <vector>
using namespace std;

int n, m;
bool check[9];
int arr[9];

// 중복 불가
// 공백 구분, 사전 순 증가, 비내림차순

void back_tracking(int cur) {
	if (cur == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			if (cur > 0 && arr[cur - 1] > i) {
				continue;
			}
			arr[cur] = i;
			back_tracking(cur + 1);
		}
	}

}

int main(void) {
	cin >> n >> m;
	back_tracking(0);

	return 0;
}
