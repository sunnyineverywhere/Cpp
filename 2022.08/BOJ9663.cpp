
#include <iostream>
#include <vector>
using namespace std;

int n;
bool column[16]; // 같은 줄에 있는 거 되는지
bool left_cross[35]; // 왼쪽 대각선 -> x + y
bool right_cross[35]; // 오른쪽 대각선 -> x - y + n

int cnt = 0;

void back_tracking(int x) {
	if (x == n) { // n개의 줄에 퀸 n개 놓는 것 성공
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (column[i] || left_cross[x + i] || right_cross[x - i + n]) {
			continue;
		}
		column[i] = true;
		left_cross[x + i] = true;
		right_cross[x - i + n] = true;
		back_tracking(x + 1); // 해당 좌표 체크하고 x + 1번째 줄로 
		column[i] = false;
		left_cross[x + i] = false;
		right_cross[x - i + n] = false;
	}

}

int main(void) {
	cin >> n;
	back_tracking(0); // 0번째 줄부터 시작
	cout << cnt;
	return 0;
}
