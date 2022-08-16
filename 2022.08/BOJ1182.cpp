#include <iostream>
using namespace std;

int n, s;
int num[21]; // 입력받은 수열
// bool check[21]; // 원소가 탐색되었는지 확인
int cnt = 0; // s가 되는 경우의 수

void back_tracking(int idx, int sum) {
	if (idx == n) {
		return;
	}
	if (sum + num[idx] == s) { // 처음에 재귀함수 돌릴때 0이 되므로 이를 방지하기 위해 num[idx]를 더한 값으로 판별한다
		cnt++;
	}

	back_tracking(idx + 1, sum); // sum에 num[idx]를 더하지 않은 버전
	back_tracking(idx + 1, sum + num[idx]); // sum에 [idx]를 더한 버전
	
}

int main(void) {

	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	back_tracking(0, 0);

	cout << cnt;

	return 0;
}
